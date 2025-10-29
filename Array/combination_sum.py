class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def helper(start,path,target):
            if target==0:
                res.append(path[:])
                return
            
            for i in range(start , len(candidates)):
                num=candidates[i]
                if num<=target:
                    path.append(candidates[i])
                    helper(i,path,target-candidates[i])
                    path.pop()
        res=[]
        helper(0,[],target)
        return res