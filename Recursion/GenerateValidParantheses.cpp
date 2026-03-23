#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;
        int open = n, close = n;

        solve(open, close, curr, res);
        return res;

    }
    void solve(int open, int close, string curr, vector<string>& res){
        if(open == 0 && close == 0){
            res.push_back(curr);
            return;
        }
        if(open != 0){
            curr.push_back('(');
            solve(open - 1, close, curr, res );
            curr.pop_back();
        }

        if(open < close){
            curr.push_back(')');
            solve(open, close - 1, curr, res);
            curr.pop_back();            
        }

        return;
    }
};  