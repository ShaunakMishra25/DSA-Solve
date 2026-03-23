#include <bits/stdc++.h>
using namespace std;
#include <vector>


class Solution {
  public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        return solve(arr, 0, k, 0);
    }
    bool solve(vector<int>& arr, int index, int k, int sum){
        if(sum == k){
            return true;
        }
        
        if(sum > k){
            return false;
        }
        
        if(index == arr.size()){
            return false;
        }
        
        return solve(arr, index + 1, k, sum + arr[index]) 
        || solve(arr, index + 1, k, sum );
        
    }
};