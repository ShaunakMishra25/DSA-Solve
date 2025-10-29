class Solution:
    def equalPartition(self, arr):
        n=len(arr)
        total=sum(arr)
        
        if total%2!=0:
            return False
        
        target=total//2
        t=[[False] * (target+1) for _ in range(n+1)]
        
        for i in range(n+1):
            t[i][0]=True
        
        for j in range(1,target+1):
            t[0][j]=False
            
        for i in range(1,n+1):
            for j in range(1,target+1):
                if arr[i-1]<=j:
                    t[i][j]=t[i-1][j-arr[i-1]] or t[i-1][j]
                else:
                    t[i][j]=t[i-1][j]
        
        return t[n][target]