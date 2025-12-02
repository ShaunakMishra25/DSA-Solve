def moveD(nums):
    n = len(nums)
    j=0
    
    for i in range(n):
        if nums[i]!=nums[j]:
            j+=1
            nums[i], nums[j] = nums[j], nums[i]
            
    return j+1