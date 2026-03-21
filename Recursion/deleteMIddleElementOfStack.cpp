class Solution {
    public:
      // Function to delete middle element of a stack.
      void deleteMid(stack<int>& s) {
          // code here..
          if(s.empty()) return;

          int k = s.size() / 2 + 1;

          solve(s, k);
      }
      void solve(stack<int>& s, int k){
        if(k == 1){
            s.pop();
            return;
        }
        int top = s.top();
        s.pop();
        solve(s, k-1);
        s.push(top);
        return;
      }
  };