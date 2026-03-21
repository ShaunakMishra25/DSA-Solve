class Solution:
    def sortStack(self, st):
        # code here 
        if len(st) == 0:
            return
        top = st.pop()
        self.sortStack(st)
        self.insert(st, top)
        return
    
    def insert(self, st, top):
        if len(st) == 0 or st[-1] <= top:
            st.append(top)
            return
        
        last = st.pop()
        self.insert(st, top)
        st.append(last)
        return

if __name__ == "__main__":
    solution = Solution()
    stack = [5, 3, 2, 4, 1]
    solution.sortStack(stack)
    print(stack)