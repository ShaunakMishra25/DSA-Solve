from itertools import count


def print1ToN(n):
    if n == 0:
        return 
    print1ToN(n-1)
    print(n, end=" ")
    return

def printNTo1(n):
    if n == 0:
        return
    print(n, end=" ")
    printNTo1(n-1)
    return

def sumOfN(n):
    if n == 0:
        return 0
    return n + sumOfN(n-1)

def reverseString(s, index):
    if index == 0:
        return s[0]
    
    return s[index] + reverseString(s, index - 1)
    
def powXN(x ,n):
    if n == 0:
        return 1
    
    if n < 0:
        return 1/powXN(x, -n)

    half = powXN(x, n //2)

    if n % 2 == 0:
        return half * half
    else:
        return x * half * half

def checkPalindrome(s, index):
    if index > len(s) // 2:
        return True
    
    if s[index] != s[len(s) - index - 1]:
        return False
    
    return checkPalindrome(s, index + 1)

def fibonacci(n):
    if n <= 1:
        return n
    
    return fibonacci(n-1) + fibonacci(n-2)

def countAllOccurrences(arr, x, index = 0):
    if index == len(arr):
        return 0

    if arr[index] == x:
        return 1 + countAllOccurrences(arr, x, index + 1)
    else:
        return countAllOccurrences(arr, x, index + 1)


def binarySearch(arr, x, low, high):
    mid = (low + high) // 2

    if arr[mid] == x:
        return mid
    elif arr[mid] < x:
        return binarySearch(arr, x, mid + 1, high)
    else:
        return binarySearch(arr, x, low, mid - 1)

def sortArray(arr, index):
    if index == len(arr):
        return
    
    if arr[index] > arr[index + 1]:
        arr[index], arr[index + 1] = arr[index + 1], arr[index]
        sortArray(arr, index + 1)
    else:
        sortArray(arr, index + 1)
    return
