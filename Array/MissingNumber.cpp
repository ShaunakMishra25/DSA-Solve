class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n = nums.size();
        // int sum = (n * (n+1))/2;
        // int res=0;
        // for(int i=0; i<n; i++){
        //     res+=nums[i];
        // }
        // return sum-res;       
        
        int s = 0;
        int e = 0;

        for ( int num  : nums) s^= num;
        for ( int i=0; i<=nums.size(); i++) e^= i;

        return s^e;

    }
};

