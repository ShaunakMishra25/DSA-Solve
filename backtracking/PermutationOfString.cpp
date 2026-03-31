#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<string> findPermutation(string &s) {
        // Code here there
        vector<string> res;
        solve(s, 0, res);
        return res;
    }
    void solve(string &s, int start, vector<string>& res){
        if(start == s.size()){
            res.push_back(s);
            return;
        }
        
        unordered_set<int> seen;
        
        for(int i = start; i < s.size(); i++){
            if(seen.find(s[i]) != seen.end()) continue;
            
            seen.insert(s[i]);
            
            swap(s[start], s[i]);
            solve(s, start + 1, res);
            swap(s[start], s[i]);
        }
    }
};
