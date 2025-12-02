def maxSubArraySUum(nums):
    currSum=0
    maxSum = float('-inf')
    
    for num in nums:
        currSum = max(num, currSum+num)
        maxSum = max(currSum, maxSum)
        
    return maxSum