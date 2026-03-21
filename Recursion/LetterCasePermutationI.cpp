#include <bits/stdc++.h>
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        string current;
        vector<string> res;
        solve(s, 0, current,  res);
        return res;
    }
    void solve(string s, int index, string current, vector<string>& res){
        if(index == s.size()){
            res.push_back(current);
            return;
        }

        solve(s, index+1, current + (char)tolower(s[index]), res);
        solve(s, index+1, current + (char)toupper(s[index]), res);
    
    return;
    }
};