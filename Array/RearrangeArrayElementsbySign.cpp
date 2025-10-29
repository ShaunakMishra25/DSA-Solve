#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int pos = 0 , neg=1;

        for(int i =0; i < n; i++){
            if(nums[i] > 0){
                ans[pos] = nums[i];
                pos += 2;
            }else{
                ans[neg] = nums[i];
                neg += 2;
            }
        }
        return nums;
    }
};
int main(){
    Solution sol;
    vector<int> nums= {3,1,-2,-5,2,-4};
    vector<int> res= sol.rearrangeArray(nums);
    for(int i=0; i<res.size(); i++){    
        cout<<res[i]<<" ";
    }
    return 0;
}