#include <iostream>
#include <stack>

class Solution {
public:
    void sortStack(std::stack<int>& st) {
        if (st.empty()) {
            return;
        }
        int top = st.top();
        st.pop();
        sortStack(st);
        insert(st, top);
    }

    void insert(std::stack<int>& st, int top) {
        if (st.empty() || st.top() <= top) {
            st.push(top);
            return;
        }
        int last = st.top();
        st.pop();
        insert(st, top);
        st.push(last);
    }
};

int main() {
    Solution solution;
    std::stack<int> stack;
    for (int x : {5, 3, 2, 4, 1}) {
        stack.push(x);
    }
    solution.sortStack(stack);

    // Print stack (pop to display; reverse order for correct output)
    std::stack<int> temp;
    while (!stack.empty()) {
        temp.push(stack.top());
        stack.pop();
    }
    std::cout << "[";
    bool first = true;
    while (!temp.empty()) {
        if (!first) std::cout << ", ";
        std::cout << temp.top();
        first = false;
        temp.pop();
    }
    std::cout << "]" << std::endl;

    return 0;
}
