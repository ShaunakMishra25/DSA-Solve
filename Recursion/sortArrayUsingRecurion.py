from typing import List


class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:

        if len(nums) <= 1:
            return nums

        rest = [nums[i] for i in range(len(nums) - 1)]
        last = nums[len(nums) - 1]
        sorted_rest = self.sortArray(rest)
        return self.insert(sorted_rest, last)

    def insert(self, nums, val):
        if len(nums) == 0 or nums[len(nums) - 1] <= val:
            return nums + [val]

        rest = [nums[i] for i in range(len(nums) - 1)]
        last = nums[len(nums) - 1]
        return self.insert(rest, val) + [last]

if __name__ == "__main__":
    solution = Solution()
    nums = [5, 3, 2, 4, 1]
    sorted_nums = solution.sortArray(nums)
    print(sorted_nums)
    