package PrefixSum;

public class ContiguousArray {
    
}
class Solution {
    public int findMaxLength(int[] nums) {
        int n = nums.length;
        int zeros = 0, ones = 0;
        int res = 0;
        HashMap<Integer, Integer> map = new HashMap<>();

        map.put(0, -1);

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) zeros++;
            else ones++;

            int diff = zeros - ones;

            if (map.containsKey(diff)) {
                res = Math.max(res, i - map.get(diff));
            } else {
                map.put(diff, i);
            }
        }
        return res;
    }
}