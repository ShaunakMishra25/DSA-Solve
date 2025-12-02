class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
                
        dict1= {}
        dict2= {}
        
        for c in s:
            dict1[c] = dict1.get(c, 0)+1
            
        for c in t:
            dict2[c] = dict2.get(c, 0) + 1
            
        return dict1 == dict2