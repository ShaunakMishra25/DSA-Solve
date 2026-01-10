package January2026;

public class MaxDotProductofTwoSubsequences {
    
}
class Solution {
    public int maxDotProduct(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;
        long NEG_INF = Long.MIN_VALUE / 2;
        long[][] dp = new long[n+1][m+1];

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                dp[i][j] = NEG_INF;
            }
        }

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                long pick = (long) nums1[i] * nums2[j];

                if(dp[i+1][j+1]>0){
                    pick += dp[i+1][j+1];
                }

                long skip1 = dp[i+1][j];
                long skip2 = dp[i][j+1];

                dp[i][j] = Math.max(pick, Math.max(skip1, skip2));
            }
        }

        return (int) dp[0][0];

    }
}