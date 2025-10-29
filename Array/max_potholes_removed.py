def max_potholes_removed(n, roadA, roadB):
    from functools import lru_cache
    
    # Prefix Sum for efficient pothole counting
    def build_prefix_sum(road):
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + (1 if road[i] in ['X', 'x'] else 0)
        return prefix
    
    prefixA = build_prefix_sum(roadA)
    prefixB = build_prefix_sum(roadB)
    
    def count_potholes(prefix, start, end):
        if start < 0 or end < 0 or start > end or end >= n:
            return 0
        return prefix[end + 1] - prefix[start]
    
    # Recursion + Precomputation with memoization
    @lru_cache(maxsize=None)
    def can_reach(pos, road, blockA_start, blockA_end, blockB_start, blockB_end):
        if pos >= n - 1:
            return True
        
        # Check if current position is blocked
        if road == 0 and blockA_start <= pos <= blockA_end:
            return False
        if road == 1 and blockB_start <= pos <= blockB_end:
            return False
        
        current_road_str = roadA if road == 0 else roadB
        # All cells are passable - potholes will be removed by blocking segments
        # No need to check for 'X' or 'x' here since they're just potholes, not obstacles
        
        # Try moving forward on same road
        if pos + 1 < n:
            next_blocked = False
            if road == 0 and blockA_start <= pos + 1 <= blockA_end:
                next_blocked = True
            if road == 1 and blockB_start <= pos + 1 <= blockB_end:
                next_blocked = True
            
            if not next_blocked:
                # All cells are passable - potholes are not obstacles
                if can_reach(pos + 1, road, blockA_start, blockA_end, blockB_start, blockB_end):
                    return True
        
        # Try switching roads and then moving forward
        other_road = 1 - road
        other_blocked = False
        if other_road == 0 and blockA_start <= pos <= blockA_end:
            other_blocked = True
        if other_road == 1 and blockB_start <= pos <= blockB_end:
            other_blocked = True
        
        if not other_blocked:
            # All cells are passable - potholes are not obstacles
            # After switching, try to move forward
            if pos + 1 < n:
                next_blocked_other = False
                if other_road == 0 and blockA_start <= pos + 1 <= blockA_end:
                    next_blocked_other = True
                if other_road == 1 and blockB_start <= pos + 1 <= blockB_end:
                    next_blocked_other = True
                
                if not next_blocked_other:
                    if can_reach(pos + 1, other_road, blockA_start, blockA_end, blockB_start, blockB_end):
                        return True
        
        return False
    
    def path_exists(blockA_start, blockA_end, blockB_start, blockB_end):
        can_reach.cache_clear()
        
        # Try starting from road A
        if not (blockA_start <= 0 <= blockA_end):
            if can_reach(0, 0, blockA_start, blockA_end, blockB_start, blockB_end):
                return True
        
        # Try starting from road B
        if not (blockB_start <= 0 <= blockB_end):
            if can_reach(0, 1, blockA_start, blockA_end, blockB_start, blockB_end):
                return True
        
        return False
    
    # Greedy approach with precomputation
    max_removed = 0
    
    # Generate all possible segments
    segments_A = [(-1, -1, 0)]  # No segment option
    for start in range(n):
        for end in range(start, n):
            potholes = count_potholes(prefixA, start, end)
            segments_A.append((start, end, potholes))
    
    segments_B = [(-1, -1, 0)]  # No segment option
    for start in range(n):
        for end in range(start, n):
            potholes = count_potholes(prefixB, start, end)
            segments_B.append((start, end, potholes))
    
    # Greedy: Sort by pothole count descending
    segments_A.sort(key=lambda x: x[2], reverse=True)
    segments_B.sort(key=lambda x: x[2], reverse=True)
    
    # For each segment A, find best compatible segment B
    for startA, endA, potholesA in segments_A:
        for startB, endB, potholesB in segments_B:
            if path_exists(startA, endA, startB, endB):
                total_removed = potholesA + potholesB
                max_removed = max(max_removed, total_removed)
                break  # Greedy: take first valid option
    
    return max_removed

# Alternative BFS-based solution to avoid recursion issues
def max_potholes_removed_bfs(n, roadA, roadB):
    from collections import deque
    
    # Prefix Sum for efficient pothole counting
    def build_prefix_sum(road):
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + (1 if road[i] in ['X', 'x'] else 0)
        return prefix
    
    prefixA = build_prefix_sum(roadA)
    prefixB = build_prefix_sum(roadB)
    
    def count_potholes(prefix, start, end):
        if start < 0 or end < 0 or start > end or end >= n:
            return 0
        return prefix[end + 1] - prefix[start]
    
    # BFS-based path checking to avoid recursion
    def path_exists(blockA_start, blockA_end, blockB_start, blockB_end):
        queue = deque()
        visited = set()
        
        # Try starting positions
        if not (blockA_start <= 0 <= blockA_end):
            queue.append((0, 0))  # (position, road)
            visited.add((0, 0))
        
        if not (blockB_start <= 0 <= blockB_end):
            queue.append((0, 1))
            visited.add((0, 1))
        
        while queue:
            pos, road = queue.popleft()
            
            if pos == n - 1:
                return True
            
            # Try moving forward on same road
            if pos + 1 < n:
                next_blocked = False
                if road == 0 and blockA_start <= pos + 1 <= blockA_end:
                    next_blocked = True
                if road == 1 and blockB_start <= pos + 1 <= blockB_end:
                    next_blocked = True
                
                if not next_blocked:
                    # All cells are passable - no need to check for potholes
                    if (pos + 1, road) not in visited:
                        queue.append((pos + 1, road))
                        visited.add((pos + 1, road))
            
            # Try switching roads at same position
            other_road = 1 - road
            other_blocked = False
            if other_road == 0 and blockA_start <= pos <= blockA_end:
                other_blocked = True
            if other_road == 1 and blockB_start <= pos <= blockB_end:
                other_blocked = True
            
            if not other_blocked:
                # All cells are passable - no need to check for potholes
                if (pos, other_road) not in visited:
                    queue.append((pos, other_road))
                    visited.add((pos, other_road))
        
        return False
    
    # Greedy approach
    max_removed = 0
    
    # Generate segments with pothole counts
    segments_A = [(-1, -1, 0)]
    for start in range(n):
        for end in range(start, n):
            potholes = count_potholes(prefixA, start, end)
            segments_A.append((start, end, potholes))
    
    segments_B = [(-1, -1, 0)]
    for start in range(n):
        for end in range(start, n):
            potholes = count_potholes(prefixB, start, end)
            segments_B.append((start, end, potholes))
    
    # Sort by pothole count (greedy)
    segments_A.sort(key=lambda x: x[2], reverse=True)
    segments_B.sort(key=lambda x: x[2], reverse=True)
    
    # Find best combination
    for startA, endA, potholesA in segments_A:
        for startB, endB, potholesB in segments_B:
            if path_exists(startA, endA, startB, endB):
                total_removed = potholesA + potholesB
                max_removed = max(max_removed, total_removed)
                break  # Greedy choice
    
    return max_removed

# Test with examples
if __name__ == "__main__":
    # Example 1
    print("Example 1:")
    result1 = max_potholes_removed_bfs(5, ".....", ".....")
    print(f"Result: {result1}")  # Expected: 0
    
    # Example 2
    print("\nExample 2:")
    result2 = max_potholes_removed_bfs(7, "X.X.X.X", "X.X.X.X")
    print(f"Result: {result2}")  # Expected: 4
    
    # Example 3
    print("\nExample 3:")
    result3 = max_potholes_removed_bfs(7, "...xXXX", "xxX....")
    print(f"Result: {result3}")  # Expected: 6
    
    # Test your input
    print("\nYour input:")
    result4 = max_potholes_removed_bfs(7, "...xxxx", "xxx....")
    print(f"Result: {result4}")

# For submission (use BFS version to avoid recursion issues):
def solve():
    n = int(input())
    roadA = input().strip()
    roadB = input().strip()
    print(max_potholes_removed_bfs(n, roadA, roadB))