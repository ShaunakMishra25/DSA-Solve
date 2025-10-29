#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std;
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        if( n < 2 * k ) return false;   

        vector<bool> inc(n-k+1, false);
        
        for(int i =0 ; i< n-k+1; i++){
            bool flg=true;
            for(int j=i; j<i<k-1; j++){
                if(nums[j]>nums[j+1]){
                    flg=false;
                    break;
                }
            }
            inc[i]=flg;
        }

        for(int i = 0 ; i +k < inc.size() ; i++){
            if(inc[i] && inc[i+k]){
                return true;
            }
        }
        return false;        
    }
};