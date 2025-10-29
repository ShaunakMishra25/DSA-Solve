class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def inorder(node, arr):
            if not node:
                return
            
            inorder(node.left, arr)
            arr.append(node.val)
            inorder(node.left, arr)
            
            res=[]
            inorder(root, res)
            return res 