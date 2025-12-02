class Solution:
    def largestOddNumber(self, num: str) -> str:
        j = -1 
        for i in range(len(num),-1,-1):
            if (ord(num[i]) - ord('0')) % 2 == 1:
                j=i
                break
        
        if j==-1:
            return ""
        
        res=""
        for i in range(0,j+1):
            res+=num[i]
            
        return res