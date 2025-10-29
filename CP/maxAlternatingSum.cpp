#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long n = nums.size();
        long long dp[n][2];
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - nums[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + nums[i]);
        }
        return dp[n - 1][1];
    
    }
};