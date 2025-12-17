package KadanesAlgorithm;

public class MaximumSubarraySumwithOneDeletion {
    public static void main(String[] args) {
        Solution s1 = new Solution();
        int arr[] = {1,-3,2,3,-4};
        System.out.println(s1.maximumSum(arr));
    }
}
class Solution {
    public int maximumSum(int[] arr) {
        int noDelete = arr[0];
        int oneDelete = 0;
        int res = arr[0];

        for(int i = 1; i < arr.length; i++){
            oneDelete = Math.max(oneDelete + arr[i], noDelete);
            noDelete = Math.max(noDelete + arr[i], arr[i]);
            res = Math.max(res, Math.max(oneDelete, noDelete));
        }
        return res;
    }
}
