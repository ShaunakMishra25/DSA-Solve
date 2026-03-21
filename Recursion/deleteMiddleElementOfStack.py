class Solution:
    def deleteMid(self, stack):
        #code here
        if len(stack) == 0:
            return
        k = len(stack ) // 2 + 1

        self.solve(stack, k)
        return
    
    def solve(self, stack, k):
        if k == 1:
            stack.pop()
            return
        top = stack.pop()
        self.solve(stack, k-1)
        stack.append(top)
        return


if __name__ == "__main__":
    stack = [1, 2, 3, 4, 5]
    solution = Solution()
    solution.deleteMid(stack)
    print(stack)