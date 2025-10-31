# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]: 
        from collections import deque
        
        parent = {}
        def distance(node, par=None):
            if not node: 
                return None
            
            parent[node]= par
            distance(node.left, node)
            distance(node.right, node)
        distance(root)
        
        visited = set()
        q=deque()
        q.append((target,0))
        visited.add(target)
        
        res=[]
        
        while q:
            node, dist = q.popleft()
            
            if dist == k:
                res.append(node.val)
            
            if dist> k :
                break
            
            for n in [node.left, node.right, parent[node]]:
                if n and n not in visited:
                    visited.add(n)
                    q.append((n, dist+1))
        return res