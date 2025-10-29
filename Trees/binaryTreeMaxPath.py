# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        def dfs(node):
            if not node:
                return 0
            
            left=dfs(node.left)
            right=dfs(node.right)
            
            leftM=max(left,0)
            rightM=max(right,0)
            
            res[0]=max(res[0], node.val+leftM+rightM)
            
            return node.val+max(leftM,rightM)
        
        res=[root.val]
        dfs(root)
        return res[0]