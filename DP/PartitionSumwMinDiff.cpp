class Solution {
  public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int range = 0;
        for (int num : arr) range += num;  

        vector<vector<bool>> dp(n + 1, vector<bool>(range + 1, false));

        for (int i = 0; i <= n; i++) dp[i][0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= range; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        int s1 = 0;
        for (int j = range / 2; j >= 0; j--) {
            if (dp[n][j]) {
                s1 = j;
                break;
            }
        }

        return range - 2 * s1;
    }
};
