def LongestRepeatingCharacterReplacement(s: str, k: int) -> int:
    count={}
    l=0
    maxLen=0
    maxCount=0
    
    for r in range(len(s)):
        count[s[r]] = count.get(s[r],0)+1
        maxCount = max(maxCount, count[s[r]])
        
        while (r-l+1) -maxCount > k:
            count[s[l]] -=1
            l+=1
        maxLen= max(maxLen, r-l+1)
    return maxLen

print(LongestRepeatingCharacterReplacement("AAABABB", 1))   