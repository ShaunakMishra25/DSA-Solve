#include <bits/stdc++.h>
using namespace std;
#include <vector>


class Solution {
  public:
    int checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        return solve(arr, 0, k, 0);
    }
    int solve(vector<int>& arr, int index, int k, int sum){
        if(sum == k){
            return 1;
        }
        
        if(sum > k){
            return 0;
        }
        
        if(index == arr.size()){
            return 0;
        }
        
        return solve(arr, index + 1, k, sum + arr[index]) 
        +solve(arr, index + 1, k, sum );
        
    }
};