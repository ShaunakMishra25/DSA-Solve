class Solution {
  public:
    int dp[501][501];
    bool pal[501][501];

    void computePalindrome(string &s) {
        int n = s.size();
        memset(pal, false, sizeof(pal));
        
        for (int i = 0; i < n; i++) {
            pal[i][i] = true; // single char
            if (i < n - 1) pal[i][i + 1] = (s[i] == s[i + 1]);
        }
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                pal[i][j] = (s[i] == s[j]) && pal[i + 1][j - 1];
            }
        }
    }

    int solve(string &s, int i, int j) {
        if (i >= j) return 0;
        if (pal[i][j]) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            int left, right;

            // ✅ Check memoization before recursive call
            if (dp[i][k] != -1)
                left = dp[i][k];
            else
                left = solve(s, i, k);

            if (dp[k + 1][j] != -1)
                right = dp[k + 1][j];
            else
                right = solve(s, k + 1, j);

            int temp = 1 + left + right;
            ans = min(ans, temp);
        }
        return dp[i][j] = ans;
    }

    int palPartition(string &s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        computePalindrome(s);
        return solve(s, 0, n - 1);
    }
};
