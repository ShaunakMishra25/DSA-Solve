# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        def bfs(node):
            if not node:
                return []
            
            res = []
            q = deque([node])
            ltor = True 
            
            while q:
                lev = []
                for _ in range(len(q)):
                    node = q.popleft()
                    lev.append(node.val)

                    if node.left:
                        q.append(node.left)
                    if node.right:
                        q.append(node.right)
                
                if not ltor:
                    lev.reverse()

                res.append(lev)
                ltor = not ltor
            
            return res
        
        return bfs(root)