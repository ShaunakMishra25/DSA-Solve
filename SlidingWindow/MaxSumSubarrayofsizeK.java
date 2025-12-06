public class MaxSumSubarrayofsizeK {
    public static void main(String[] args) {
        Solution s1 = new Solution();
        int[] arr = {2,1,5,1,3,2};
        int k = 3;
        int result = s1.maxSubarraySum(arr, k);
        System.out.println(result);
    }    
}
class Solution {
    public int maxSubarraySum(int[] arr, int k) {
        // Code here
        int n = arr.length;
        int currSum=0;
        for(int i = 0; i<k; i++){
            currSum += arr[i];
        }
        int maxSum = currSum;
        
        for(int i =k; i<n; i++){
            currSum += arr[i];
            currSum -= arr[i-k];
            maxSum = Math.max(currSum, maxSum);
        }
        return maxSum;
    }
}