package Strings;

public class MinimumDeletionCosttoMakeAllCharactersEqual {
    
}
class Solution {
    public long minCost(String s, int[] cost) {
        String ans = s;

        long totalCost = 0;
        long charCost[] = new long[26];

        for(int i = 0; i < ans.length(); i++){
            totalCost += cost[i];
            charCost[ans.charAt(i) - 'a'] += cost[i];
        }

        long maxKeepCost = 0;
        for(long c : charCost){
            maxKeepCost = Math.max(maxKeepCost, c);
        }

        return (totalCost - maxKeepCost);
    }
}