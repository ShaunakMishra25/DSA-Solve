class Solution:
    def knapsack(self, W, val, wt):
        n = len(wt)
        t = [[-1 for _ in range(W + 1)] for _ in range(n + 1)]

        def solve(n, W):
            if n == 0 or W == 0:
                return 0
            if t[n][W] != -1:
                return t[n][W]
            if wt[n - 1] <= W:
                t[n][W] = max(
                    val[n - 1] + solve(n - 1, W - wt[n - 1]),
                    solve(n - 1, W)
                )
            else:
                t[n][W] = solve(n - 1, W)
            return t[n][W]

        return solve(n, W)
