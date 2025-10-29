class Solution:
    def postrderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def postorder(node, arr):
            if not node:
                return
            
            postorder(node.left, arr)
            postorder(node.right, arr)
            arr.append(node.val)
        
        res=[]
        postorder(root, res)
        return res
        