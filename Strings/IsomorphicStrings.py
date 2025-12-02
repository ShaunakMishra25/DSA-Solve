class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        dict1={}
        dict2={}
        for i in range(len(s)):
            c1, c2 = s[i], t[i] 

            if c1 in dict1 and dict1[c1] != c2:
                return False
            
            if c2 in dict2 and dict2[c2] != c1:
                return False
            
            dict1[c1] = c2
            dict2[c2] = c1
            
        return True