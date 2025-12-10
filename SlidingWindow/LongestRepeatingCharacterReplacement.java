public class LongestRepeatingCharacterReplacement {
    public static void main(String[] args) {
        Solution s1 = new Solution();
        String s = "AABAB";
        int k = 2;
        s1.characterReplacement(s, k);
    }
}

class Solution{
    public int characterReplacement(String s, int k) {
        int n = s.length();
        int low = 0, res=  0;
        int windowSize =0, maxCount = 0;
        
        int arr[] = new int[26];

        for(int high = 0; high < n; high++){
            char ch = s.charAt(high);
            arr[ch - 'A']++;

            maxCount = Math.max(maxCount, arr[ch - 'A']);
            windowSize = high - low + 1;

            while(windowSize - maxCount > k){
                char chLow = s.charAt(low);
                arr[chLow - 'A']--;
                low++;
                windowSize = high - low + 1;
            }
            res = Math.max(res, windowSize);
        }
        return res;
    }
}
