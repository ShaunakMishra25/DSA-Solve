# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:      
        def dfs(node):
            if not node:
                return 0, 0
            
            curr=node
            left_h, left_di =dfs(curr.left)
            right_h, right_di = dfs(curr.right)
            
            curr_di= left_h+right_h
            
            dia= max(left_di, right_di, curr_di)
            return 1 + max(left_h, right_h), dia
        return dfs(root)
