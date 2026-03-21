#include <stack>
#include <iostream>

class Solution {
    public:
      void reverseStack(std::stack<int> &st) {
          // code here
          if(st.empty()) return;

          int top = st.top();
          st.pop();
        
          reverseStack(st);
          insert(st, top);
      }
      void insert(std::stack<int>& st, int top){
        if(st.empty()){
            st.push(top);
            return;
        }
        int last = st.top();
        st.pop();
        insert(st, top);
        st.push(last);
        return;
      }
  };


int main() {
    Solution solution;
    std::stack<int> st;
    for (int x : {1, 2, 3, 4, 5}) {
        st.push(x);
    }
    solution.reverseStack(st);
    while(!st.empty()){
        std::cout << st.top() << " ";
        st.pop();
    }
    return 0;
}