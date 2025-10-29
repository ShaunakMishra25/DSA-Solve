class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int n = nums.size();
        int count=0;
        int c=0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i]== 1) c++;
            else {
                count= max (count , c);
                c=0;
            }
        }
        return max ( count , c);
    }
};