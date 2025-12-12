public class MinimumWindowSubstring {
    public static void main(String[] args) {
        Solution s1 = new Solution();
        String s = "ADOBECODEBANC", t = "ABC";
        System.out.println(s1.minWindow(s, t));
    }
}

class Solution {
    public String minWindow(String s, String t) {
        int minLen = Integer.MAX_VALUE;
        int startIndex = 0, low = 0, windowSize = 0;
        int have[] = new int[256];
        int need[] = new int[256];

        for(char ch : t.toCharArray()) need[ch]++;

        int required = 0;
        for(int c : need){
            if(c>0) required++;
        }

        int formed = 0;

        
        for(int high = 0; high < s.length(); high++){
            char ch = s.charAt(high);
            have[ch]++;

            if(have[ch] == need[ch]) formed++;
            
            while(formed == required){
                windowSize = high - low + 1;

                if(windowSize < minLen){
                    minLen = windowSize;
                    startIndex = low;
                }

                char leftChar = s.charAt(low);
                have[leftChar]--;
                if(have[leftChar] < need[leftChar]) formed--;
                low++;
            }
        }

        if(minLen == Integer.MAX_VALUE) return "";
        return s.substring(startIndex, startIndex + minLen);
    }
}