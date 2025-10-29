class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector <int> coeffs(n,0);
        coeffs[0]=1;

        for(int i=1;i<n;i++){
            coeffs[i]=1;
            for(int j=i-1;j>0;j--){
                coeffs[j] = (coeffs[j] + coeffs[j - 1]) % 10;
            }
        }

        int res=0;
        for (int i = 0; i < n; i++) {
            res = (res + nums[i]*coeffs[i]) % 10;
        }
        return res;
    }
};
