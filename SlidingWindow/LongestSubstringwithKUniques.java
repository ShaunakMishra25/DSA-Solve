import java.util.HashMap;

public class LongestSubstringwithKUniques {
    public static void main(String[] args) {
        Solution s1 = new Solution();
        String s = "aabacbebebc";
        int k =3;
        System.out.println(s1.longestKSubstr(s, k));
    }
}

class Solution {
    public int longestKSubstr(String s, int k) {
        // code here
        int n = s.length();
        int ans = -1, low =0;
        
        HashMap <Character, Integer> f = new HashMap<>();

        for(int high = 0; high < n; high++){
            char c = s.charAt(high);
            f.put(c, f.getOrDefault(c,0) + 1);
            
            if(f.size()==k) ans = Math.max(ans, high-low+1);

            while(f.size()>k){
                char ch = s.charAt(low);
                int updatedFreq = f.getOrDefault(ch, 0) -1;

                if(updatedFreq==0)f.remove(ch);
                else f.put(ch, updatedFreq);

                low++;
            }
        }
        return ans;
    }
}


