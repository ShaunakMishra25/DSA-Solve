class Solution {
  public:
    int lcs(string &s1, string &s2) {
        function<int(int,int)> solve = [&](int n, int m) -> int {
            if (n == 0 || m == 0) return 0;

            if (s1[n-1] == s2[m-1]) {
                return 1 + solve(n-1, m-1);
            }
            return max(solve(n-1, m), solve(n, m-1));
        };

        return solve(s1.size(), s2.size());
    }
};
