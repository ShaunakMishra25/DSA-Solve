import java.util.HashMap;

public class LongestSubstringWithoutRepeatingCharacters {
    public static void main(String[] args) {
        Solution s1 = new Solution();
        String s = "abcabcbb";
        System.out.println(s1.lengthOfLongestSubstring(s));
    }
}
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int low = 0,  res = 0;

        HashMap<Character, Integer> f = new HashMap<>();

        for(int high = 0; high < n; high++){

            char ch = s.charAt(high);
            f.put(ch, f.getOrDefault(ch, 0)+1);

            while(f.get(ch)>1){

                char chLow = s.charAt(low);
                int updatedFreq = f.getOrDefault(chLow, 0)-1;

                if(updatedFreq == 0) f.remove(chLow);
                else f.put(chLow, updatedFreq);

                low++;
            }
            res = Math.max(res, high - low + 1);
        }

        return res;
    }
}