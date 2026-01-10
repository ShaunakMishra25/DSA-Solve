package PrefixSum;

public class FindPivotIndex {
    
}
class Solution {
    public int pivotIndex(int[] nums) {
        int leftSum = 0, rightSum = 0;
        int totalSum = 0;
        for(int x : nums){
            totalSum += x;
        }
        for(int i = 0; i < nums.length; i++){
            rightSum = totalSum - leftSum - nums[i];
            if(leftSum == rightSum) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
}