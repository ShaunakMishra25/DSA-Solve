class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        str1= sorted(strs)
        
        first= str1[0]
        last= str1[-1]
        
        n = min(len(first), len(last))
        
        for i in range(n):
            if first[i] != last[i]:
                return ans
            
            ans += first[i]
            
        return ans