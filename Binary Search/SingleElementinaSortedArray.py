class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        def binSer(arr, l, r):
            if l == r:
                return arr[l]

            mid = (l + r) // 2

            if mid % 2 == 0:
                if arr[mid] == arr[mid + 1]:
                    return binSer(arr, mid + 2, r)
                else:
                    return binSer(arr, l, mid)
            else:
                if arr[mid] == arr[mid - 1]:
                    return binSer(arr, mid + 1, r)
                else:
                    return binSer(arr, l, mid - 1)

        return binSer(nums, 0, len(nums) - 1)