import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ThreeSumClosest {
    public static void main(String[] args) {
        
    }
}
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;

        int ans = nums[0] + nums[1] + nums[2];
        int mindiff = Math.abs(target-ans);

        for(int i =0; i< n; i++){
            int left = i+1;
            int right = n-1;

            while(left<right){
                int currSum = nums[i]+ nums[left] + nums[right];
                int diff = Math.abs(target-currSum);

                if(diff < mindiff){
                    mindiff = diff;
                    ans = currSum;
                }

                if(currSum == target ) return currSum;
                else if(currSum < target) left++;
                else right--;
            }
        }
        return ans;
    }
}