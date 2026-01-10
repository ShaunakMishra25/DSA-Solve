package January2026;

public class MinimumASCIIDeleteSumforTwoStrings {
    
}
class Solution {
    public int minimumDeleteSum(String s1, String s2) {
        int n = s1.length();
        int m = s2.length();
        int dp[][] = new int[n + 1][m + 1];

        for(int i = n - 1 ; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                if(s1.charAt(i) == s2.charAt(j)){
                    dp[i][j] = (int) s1.charAt(i) + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = Math.max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        int sum1 = 0, sum2 = 0;

        for(char c : s1.toCharArray()) sum1 += (int)c;
        for(char c : s2.toCharArray()) sum2 += (int)c;

        int keep = dp[0][0];

        return sum1 + sum2 - 2 * keep;
    }
}