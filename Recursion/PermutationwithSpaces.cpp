#include <bits/stdc++.h>
using namespace std;
#include <string>
#include <vector>

class Solution {
  public:

    vector<string> permutation(string s) {
        // Code Here
        vector<string> res;
        solve(s, 0, string(1, s[0]), res);
        
        sort(res.begin(), res.end());
        return res;
    }
    void solve(string s, int i, string current, vector<string>& res){
        if(s.size() - 1 == i){
            res.push_back(current);
            return;
        }
        
        solve(s, i + 1, current + s[i + 1], res);
        
        solve(s, i + 1, current + " " + s[i + 1], res);
    }
};