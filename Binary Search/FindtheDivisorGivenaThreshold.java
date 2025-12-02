public class FindtheDivisorGivenaThreshold {
    public static void main(String[] args) {
        int[] nums = {1, 2, 5, 9};
        int threshold = 6;

        Solution s1 = new Solution();
        int ans = s1.smallestDivisor(nums, threshold);
        System.out.println(ans); 
    }
}

class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        int low = 1;
        int high = 0;
        for (int num : nums) {
            high = Math.max(high, num);
        }

        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int sum = 0;

            for (int num : nums) {
                sum += Math.ceil((double) num / mid);
            }

            if (sum <= threshold) {
                ans = mid;     
                high = mid - 1;
            } else {
                low = mid + 1;  
            }
        }
        return ans;
    }
}
