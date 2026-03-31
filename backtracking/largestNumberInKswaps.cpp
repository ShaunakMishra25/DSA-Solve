#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        // code here.
        string res;
        solve(s, 0, k, res);
        return res;
    }
    void solve(string&s, int index, int k, string& res){
        res = max(res, s);
        if(k == 0 || index == s.size() - 1){
            return;
        }
        char m = *max_element(s.begin() + index, s.end());
        
        if(s[index] == m){
            solve(s, index + 1, k, res);
            return;
        }
        for(int i = index + 1; i < s.size(); i++){
            if(s[i] == m){
                swap(s[index], s[i]);    
                solve(s, index + 1, k - 1, res);
                swap(s[index], s[i]);    
            }
        }
    }
};