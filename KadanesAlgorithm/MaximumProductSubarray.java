package KadanesAlgorithm;

public class MaximumProductSubarray {
    public static void main(String[] args) {
        
    }
}
class Solution {
    public int maxProduct(int[] nums) {
        int minEnding = nums[0];
        int maxEnding = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.length; i++){
            int c1 = nums[i] * minEnding;
            int c2 = nums[i] * maxEnding;
            
            minEnding = Math.min(nums[i], Math.min(c1, c2));
            maxEnding = Math.max(nums[i], Math.max(c1, c2));
            
            ans = Math.max(ans, maxEnding);
        }
        return ans;
    }
}