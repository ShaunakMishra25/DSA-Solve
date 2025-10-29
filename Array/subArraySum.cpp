#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        map mpp;
        mpp[0]=1;
        int sum=0, res=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mpp.find(sum-k)!=mpp.end())

        }
        
    
    }
};