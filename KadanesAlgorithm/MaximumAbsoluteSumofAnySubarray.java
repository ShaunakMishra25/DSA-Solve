package KadanesAlgorithm;

public class MaximumAbsoluteSumofAnySubarray {
    public static void main(String[] args) {
        Solution s1 = new Solution();
        int arr[] = {1,-3,2,3,-4};
        System.out.println(s1.maxAbsoluteSum(arr));
    }
}
class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int maxEnding = nums[0];
        int minEnding = nums[0];
        int maxSum = nums[0];
        int minSum = nums[0];

        for (int i = 1; i < nums.length; i++) {
            maxEnding = Math.max(nums[i], maxEnding + nums[i]);
            minEnding = Math.min(nums[i], minEnding + nums[i]);

            maxSum = Math.max(maxSum, maxEnding);
            minSum = Math.min(minSum, minEnding);
        }
        return Math.max(maxSum, Math.abs(minSum));
    }
}
