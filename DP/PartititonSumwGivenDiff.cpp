class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        int total = 0;
        for (int x : arr) total += x;

        if ((total + diff) % 2 != 0) return 0;
        int target = (total + diff) / 2;
        if (target > total) return 0;

        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (arr[i-1] <= j) {
                    dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j]) % MOD;
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    }
};
