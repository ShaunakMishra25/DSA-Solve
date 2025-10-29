class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        
        stack=[]        
        res= []
        curr=root
        
        while curr or stack:
            while curr:
                stack.append(curr)
                curr=curr.left
            curr=stack.pop()
            res.append(curr.val)
            curr=curr.right
        return res