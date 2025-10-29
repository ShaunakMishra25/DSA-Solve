class Solution:
    def twoSum(self, nums, target):
        num_map = {}
        for i, num in enumerate(nums):
            comp = target - num
            if comp in num_map:
                return [num_map[comp], i]
            num_map[num] = i

# Example usage
if __name__ == "__main__":
    sol = Solution()
    nums = [2, 7, 11, 15]
    target = 9
    result = sol.twoSum(nums, target)
    print("Indices:", result)
