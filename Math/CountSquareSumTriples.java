public class CountSquareSumTriples {
    public static void main(String[] args) {
        Solution s1 = new Solution();
        int n = 5;
        int result = s1.countTriples(n);
        System.out.println(result);
    }
}
class Solution {
    public int countTriples(int n) {
        int count =0;
        for(int a = 1; a<=n; a++){
            for(int b = a+1; b<=n; b++){
                int s = a*a + b*b;
                int c = (int)Math.sqrt(s);
                if(c*c==s && c<=n) count+=2;
            }
        }
        return count;
    }
}