def twoSum(nums, k):
    i,j=0, len(nums)-1
    
    while i<j:
        if nums[i]+nums[j] == k:
            return [i,j]
        
        elif nums[i]+nums[j]<k:
            i+=1
        else:
            j-=1


def twoSum(nums, k):
    seen = {}
    
    for i, num in enumerate(nums):
        diff = k-num
        if diff in seen:
            return [seen[diff],i]
        
        seen[num]=i