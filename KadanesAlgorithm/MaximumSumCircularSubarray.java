package KadanesAlgorithm;

public class MaximumSumCircularSubarray {
   public static void main(String[] args) {
        Solution s1 = new Solution();
        int arr[] = {1,-3,2,3,-4};
        System.out.println(s1.maxSubarraySumCircular(arr));
    }
}
class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int totalSum = 0;

        int curMax = 0, maxSum = nums[0];
        int curMin = 0, minSum = nums[0];

        for (int num : nums) {
            curMax = Math.max(num, curMax + num);
            maxSum = Math.max(maxSum, curMax);

            curMin = Math.min(num, curMin + num);
            minSum = Math.min(minSum, curMin);

            totalSum += num;
        }

        if (maxSum < 0) return maxSum;

        return Math.max(maxSum, totalSum - minSum);
    }
}