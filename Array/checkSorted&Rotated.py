def check(nums):
    n = len(nums)
    count = 0
    for i in range(n):
        if nums[i] > nums[(i + 1) % n]:
            count += 1
        if count > 1:
            return False
    return True

# Example usage
if __name__ == "__main__":
    nums = [3, 4, 5, 1, 2]
    result = check(nums)
    print("Is sorted and rotated?", result)