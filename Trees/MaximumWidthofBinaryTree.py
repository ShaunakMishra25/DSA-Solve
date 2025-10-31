# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque


class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        def bfs(node):
            if not node:
                return
            
            q = deque([(root,0)])
            maxW = 0
            
            while q:
                size = len(q)
                _, fIn = q[0]
                
                for _ in range(size):
                    node, idx=q.popleft()
                    norm = idx-fIn
                    
                    if node.left:
                        q.append((node.left, 2*norm))
                    
                    if node.right:
                        q.append((node.right, 2*norm))
                    
                wid = norm+1
                maxW = max(maxW, wid)
                
            return maxW
        return bfs(root)