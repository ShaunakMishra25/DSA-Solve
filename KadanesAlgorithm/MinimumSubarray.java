package KadanesAlgorithm;

public class MinimumSubarray {
    public static void main(String[] args) {
        
    }
}
class Solution {
    static int smallestSumSubarray(int a[], int size) {
        // your code here
        int currentSum = a[0];
        int ans = a[0];
        
        for(int i = 1; i < size; i++){
            currentSum  = Math.min(currentSum + a[i], a[i]);
            ans = Math.min(ans, currentSum);
        }
        return ans;
    }
}