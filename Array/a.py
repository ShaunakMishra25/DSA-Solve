from collections import deque

class Solution:
    def maxPotholesRemoved(self, n: int, roadA: str, roadB: str) -> int:
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

        def path_exists(blockA_start, blockA_end, blockB_start, blockB_end):
            queue = deque()
            visited = set()

            if not (blockA_start <= 0 <= blockA_end):
                queue.append((0, 0))
                visited.add((0, 0))

            if not (blockB_start <= 0 <= blockB_end):
                queue.append((0, 1))
                visited.add((0, 1))

            while queue:
                pos, road = queue.popleft()

                if pos == n - 1:
                    return True

                if pos + 1 < n:
                    blocked = (road == 0 and blockA_start <= pos + 1 <= blockA_end) or \
                              (road == 1 and blockB_start <= pos + 1 <= blockB_end)
                    if not blocked and (pos + 1, road) not in visited:
                        queue.append((pos + 1, road))
                        visited.add((pos + 1, road))

                other = 1 - road
                blocked = (other == 0 and blockA_start <= pos <= blockA_end) or \
                          (other == 1 and blockB_start <= pos <= blockB_end)
                if not blocked and (pos, other) not in visited:
                    queue.append((pos, other))
                    visited.add((pos, other))

            return False

        segments_A = [(-1, -1, 0)]
        for i in range(n):
            for j in range(i, n):
                segments_A.append((i, j, count_potholes(prefixA, i, j)))

        segments_B = [(-1, -1, 0)]
        for i in range(n):
            for j in range(i, n):
                segments_B.append((i, j, count_potholes(prefixB, i, j)))

        segments_A.sort(key=lambda x: x[2], reverse=True)
        segments_B.sort(key=lambda x: x[2], reverse=True)

        max_removed = 0
        for startA, endA, potholesA in segments_A:
            for startB, endB, potholesB in segments_B:
                if path_exists(startA, endA, startB, endB):
                    max_removed = max(max_removed, potholesA + potholesB)
                    break

        return max_removed

# 👇 LeetCode-style input/output handling for multiple test cases
if __name__ == "__main__":
        n = int(input())
        roadA = input().strip()
        roadB = input().strip()
        sol = Solution()
        res = sol.maxPotholesRemoved(n, roadA, roadB)
        print(res)
