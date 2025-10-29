#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> t(n + 1, vector<int>(sum + 1, 0));

        for (int i = 0; i <= n; i++) {
            t[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] <= j) {
                    t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        return t[n][sum];
    }
};

int SubsetSumWgivenSum() {
    Solution sol;
    vector<int> arr = {2, 3, 5, 6, 8, 10};
    int sum = 10;
    cout << "Count of subsets with sum " << sum << " = " 
         << sol.countSubsetSum(arr, sum) << endl;
    return 0;
}
