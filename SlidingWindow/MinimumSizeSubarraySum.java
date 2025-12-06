public class MinimumSizeSubarraySum {
    public static void main(String[] args) {
        Solution s1 = new Solution();
        int[] arr = {2,3,1,2,4,3};
        int target = 7;
        int result = s1.minSubArrayLen(target, arr);
        System.out.println(result);
    }
}
class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length;
        int minC = Integer.MAX_VALUE;
        int sum = 0, low = 0, high = 0;

        while(high < n){
            sum += nums[high];
            high++;

            while(sum >= target){
                minC= Math.min(minC, (high-low));
                sum -= nums[low];
                low++;
            }
        }
        return minC == Integer.MAX_VALUE ? 0 : minC; 

    }
}