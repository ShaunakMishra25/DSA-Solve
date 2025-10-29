// User function Template for C++

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= capacity; w++) {
                if (wt[i - 1] <= w) {
                    // Include (stay at i, since unbounded) or exclude
                    dp[i][w] = max(val[i - 1] + dp[i][w - wt[i - 1]], 
                                   dp[i - 1][w]);
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }

        return dp[n][capacity];
    }
};
