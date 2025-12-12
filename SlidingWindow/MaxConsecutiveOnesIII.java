public class MaxConsecutiveOnesIII {
    public static void main(String[] args) {
        int []nums = {1,0,1,1,1,0,1};
        int k = 2;
        Solution s1 = new Solution();
        System.out.println(s1.longestOnes(nums, k));
    }
}

class Solution {
    public int longestOnes(int[] nums, int k) {
        int n = nums.length;
        int low = 0, res = 0;
        int windowSize = 0;
        int oneInWindow = 0, zeroInWindow = 0;

        for (int high = 0; high < n; high++) {
            if (nums[high] == 1)
                oneInWindow++;
            windowSize = high - low + 1;
            
            zeroInWindow = windowSize - oneInWindow;

            while(zeroInWindow > k){
                if(nums[low] == 1) oneInWindow--;
                low++;

                windowSize = high - low + 1;
                zeroInWindow = windowSize - oneInWindow;
            }
            res = Math.max(res, windowSize);
        }
        return res;
    }

}