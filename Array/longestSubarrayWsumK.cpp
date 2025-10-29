#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std;
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
       int n = arr.size();
        int l=0,r=0;
        int sum=0, maxLen=0;
        while(r<n){
            sum+=arr[r];

            while(sum>k){
                sum -= arr[l];
                l++;
            }
            if(sum==k) maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};