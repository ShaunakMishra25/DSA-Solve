public class SquaresofaSortedArray {
    public static void main(String[] args) {
        Solution s1 = new Solution();
        int[] nums = {-4, -1, 0, 3, 10};
        int[] result = s1.sortedSquares(nums);
        for (int num : result) {
            System.out.print(num + " ");
        }
    }
}
class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int res[] = new int[n];
        int i = 0, j = n - 1, k = n - 1;
        
        while (i <= j) {
            int left = nums[i] * nums[i];
            int right = nums[j] * nums[j];

            if (left > right) {
                res[k--] = left;
                i++;
            } else {
                res[k--] = right;
                j--;
            }
        }
        return res;
    }
}