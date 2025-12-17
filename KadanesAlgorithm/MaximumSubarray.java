package KadanesAlgorithm;

public class MaximumSubarray {
    public static void main(String[] args) {
        Solution s1 = new Solution();
    }
}
class Solution {
    public int maxSubArray(int[] nums) {
        int currentSum = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.length; i++){
            int c1 = currentSum + nums[i];
            currentSum = Math.max(currentSum + nums[i], nums[i]);

            ans = Math.max(ans, currentSum);
        }
        return ans;
           
    }
}