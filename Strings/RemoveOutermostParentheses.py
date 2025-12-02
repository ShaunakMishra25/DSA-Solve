class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        cnt =0
        res=[]
        for c in  s:
            if c == '(':
                if cnt>0:
                    res.append('(')
                cnt+=1
            elif c==')':
                cnt-=1
                if cnt>0:
                    res.append(')')
                
        return ''.join(res)