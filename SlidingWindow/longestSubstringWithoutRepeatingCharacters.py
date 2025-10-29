def longestSubstringWithoutRepeatingCharacters():
    s= input("Enter a string: ")
    charSet=set()
    left=0
    maxLength=0
    
    for right in range(len(s)):
        while s[right] in charSet:
            charSet.remove(s[left])
            left += 1
        charSet.add(s[right])
        maxLength= max(maxLength, right - left + 1)
    return maxLength
    
print( longestSubstringWithoutRepeatingCharacters())

