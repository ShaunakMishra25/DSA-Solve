#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int lcs(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> t(n+1, vector<int>(m+1, -1));
        
        function<int(int,int)> solve = [&](int i, int j) -> int {
            if (i == 0 || j == 0) return 0;
            
            if (t[i][j] != -1) return t[i][j];
            
            if (s1[i-1] == s2[j-1]) {
                return t[i][j] = 1 + solve(i-1, j-1);
            }
            
            return t[i][j] = max(solve(i-1, j), solve(i, j-1));
        };
        
        return solve(n, m);
    }
};

int main() {
    string s1 = "abcde";
    string s2 = "ace";
    
    Solution sol;
    cout << "Length of LCS: " << sol.lcs(s1, s2) << endl;
    
    return 0;
}
