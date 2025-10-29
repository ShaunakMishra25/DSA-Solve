class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < n; i++) sum += arr[i];

        if (sum % 2 != 0) return false;

        int target = sum / 2;

        vector<vector<bool>> t(n + 1, vector<bool>(target + 1, false));

        for (int i = 0; i <= n; i++) {
            t[i][0] = true;  
        }

        // fill DP
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (arr[i - 1] <= j) {
                    t[i][j] = t[i - 1][j] || t[i - 1][j - arr[i - 1]];
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        return t[n][target];
    }
};
