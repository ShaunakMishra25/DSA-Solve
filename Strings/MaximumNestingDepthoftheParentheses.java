package Strings;

public class MaximumNestingDepthoftheParentheses {
    public static void main(String[] args) {
        Solution s1 = new Solution();
        System.out.println(s1.maxDepth("(1+(2*3)+((8)/4))+1"));
    }    
}

class Solution {
    public int maxDepth(String s) {
        
        int maxCount = 0;
        int currCount = 0;
        for(char ch : s.toCharArray()){
            if(ch == '(') {
                currCount++;
                maxCount= Math.max(maxCount, currCount);
            }
            else if(ch == ')'){
            currCount--;
            } 
            else continue;
        }
        return maxCount; 
    }
}