// User function Template for C++
class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        const int MOD = 1000000007;
        int n = coins.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        
        // Base case: there is 1 way to make sum = 0 (pick nothing)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (coins[i - 1] <= j) {
                    // include coin[i-1] (stay at i) + exclude coin[i-1] (go to i-1)
                    dp[i][j] = (dp[i][j - coins[i - 1]] + dp[i - 1][j]) % MOD;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[n][sum];
    }
};
