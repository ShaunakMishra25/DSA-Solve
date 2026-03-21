// User function template for C++
#include <bits/stdc++.h>
using namespace std; 
#include <vector>
class Solution {
  public:
    // #define ll long long
    int countStrings(int n) {
        // code here
        return solve(n, "");
    }
    int solve(int n, string curr){
        if(curr.length() == n){
            return 1;
        }
        int count = 0;
        count+= solve(n, curr + '0');
        
        if(curr.empty() || curr.back() != '1'){
            count += solve(n, curr + '1');
        }
        return count;
    }
};