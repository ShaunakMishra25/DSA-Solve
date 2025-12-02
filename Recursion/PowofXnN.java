public class PowofXnN {
    public static void main(String[] args) {
        Solution s1 = new Solution();
        System.out.println(s1.myPow(2.0, -3));
    }
}
class Solution {
    public double myPow(double x, int n) {

        long N = n; 

        return pow(x, N);
    }

    private double pow(double x, long n) {

        if (n == 0) return 1;

        if (n < 0) {
            return 1 / pow(x, -n);
        }

        double half = pow(x, n / 2);   

        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
}
