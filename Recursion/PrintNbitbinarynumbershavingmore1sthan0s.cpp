#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// User function template for C++
class Solution {
  public:
    vector<string> NBitBinary(int n) {
        // Your code goes here
        vector<string> res;
        string curr;
        int zeros = 0, ones = 0;
        solve(n, zeros, ones, curr, res);
        sort(res.begin(), res.end(),  greater<string>());
        return res;
    }
    void solve(int n, int zeros, int ones, string curr, vector<string>& res){
        if(ones + zeros == n){
            res.push_back(curr);
            return;
        }
        if(ones < n){
            curr.push_back('1');
            solve(n, zeros, ones + 1, curr, res);
            curr.pop_back();
        }
        
        if(ones > zeros){
            curr.push_back('0');
            solve(n, zeros + 1, ones, curr, res);
            curr.pop_back();
        }
    return;
    }
};