public class fib {
    public static void main(String[] args) {
        Solution s1 = new Solution();
        System.out.println(s1.fibo(6,0,1));
    }
}
class Solution {
    public int fibo(int n, int a, int b) {
        if(n==0) return a;
        if(n==1) return b;
        return fibo(n-1, b, a+b);
    }
}