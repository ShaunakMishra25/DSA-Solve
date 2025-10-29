#include <cstring> // Required for memset
#include <algorithm> // Required for std::max
#include <iostream>
using namespace std;

int t[102][1002];

int knapsack(int wt[], int val[], int W, int n) {
    if (n == 0 || W == 0) {
        return 0;
    }
    if (t[n][W] != -1) {
        return t[n][W];
    }
    if (wt[n - 1] <= W) {
        return t[n][W] = std::max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1),
                           knapsack(wt, val, W, n - 1));
    } else {
        return t[n][W] = knapsack(wt, val, W, n - 1);
    }
}

int main() {
    // Initialize the memoization table
    memset(t, -1, sizeof(t));

    // Example usage:
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    cout << "Maximum value: " << knapsack(wt, val, W, n) << endl;

    return 0;
}