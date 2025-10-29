from typing import List

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates.sort()  # Sort to handle duplicates

        def helper(start, path, remain):
            if remain == 0:
                res.append(path[:])
                return

            for i in range(start, len(candidates)):
                # Skip duplicates
                if i > start and candidates[i] == candidates[i - 1]:
                    continue
                if candidates[i] > remain:
                    break

                path.append(candidates[i])
                helper(i + 1, path, remain - candidates[i])  # i+1 → no reuse
                path.pop()  # Backtrack

        helper(0, [], target)
        return res

# Test code
if __name__ == "__main__":
    s = Solution()
    candidates = [10, 1, 2, 7, 6, 1, 5]
    target = 8
    output = s.combinationSum2(candidates, target)
    print("Combinations that sum to", target, "are:")
    for combo in output:
        print(combo)
