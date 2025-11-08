class Solution:
    def reverseWords(self, s: str) -> str:
        stack=[]
        word=""

        for c in s:
            if c != " ":
                word+=c
            else:
                if word:
                    stack.append(word)
                    word=""
            
            
        if word:
            stack.append(word)
            
        res=""
        while stack:
            res+=stack.pop()
            if stack:
                res+=" "
        return res