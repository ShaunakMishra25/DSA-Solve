class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[]]

        for num in nums:
            res += [curr + [num] for curr in res]
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3]
    print(s.subsets(nums))