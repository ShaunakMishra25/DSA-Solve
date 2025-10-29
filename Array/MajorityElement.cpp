#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cd = 0;
        int me = 0;
        for(int i = 0; i < n; i++){
            if(cd == 0){
                me = nums[i];
            }
            if(nums[i] == me){
                cd++;
            }else{
                cd--;
            }
        }
        return me;
    }
};