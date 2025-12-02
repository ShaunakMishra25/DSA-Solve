def rotateArray(nums, k):
    if not nums:
        return nums
    
    def rotate(arr, i, j):
        while i<j:
            arr[i], arr[j]= arr[j], arr[i]
            i+=1
            j-=1
    n= len(nums)
    k = k%n

    rotate(nums, 0 , n-1)
    rotate(nums, 0 , k-1)
    rotate(nums, k, n-1)