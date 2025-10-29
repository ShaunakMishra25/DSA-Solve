#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        while(i>=0 and nums[i]>=nums[i+1]) i--;
        if(i>=0){
            int j = n-1;
            while(nums[j]<= nums[i]) j--;
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1, nums.end());
        return;
    }
};
int main(){
    Solution sol;
    vector<int> nums= {1,2,3};
    sol.nextPermutation(nums);
    for(int i=0; i<nums.size(); i++){    
        cout<<nums[i]<<" ";
    }
    return 0;
}