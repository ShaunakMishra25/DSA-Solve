// User function Template for C++

class Solution {
  public:
    int minCoins(vector<int> &coins, int amount) {
        int n = coins.size();
        const int INF = 1e9;
        
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INF));
        
        for (int i = 0; i <= n; i++) dp[i][0] = 0;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i - 1] <= j) {
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return (dp[n][amount] >= INF) ? -1 : dp[n][amount];
    }
};
