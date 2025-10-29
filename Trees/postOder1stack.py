class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        stack = []
        last_visited = None
        curr = root

        while curr or stack:
            while curr:
                stack.append(curr)
                curr = curr.left

            peek = stack[-1]
            # if right child exists and hasn't been visited yet, go right
            if peek.right and last_visited != peek.right:
                curr = peek.right
            else:
                res.append(peek.val)
                last_visited = stack.pop()

        return res
