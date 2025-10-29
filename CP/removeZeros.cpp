class Solution {
public:
    long long removeZeros(long long n) {
        long long res = 0;
        long long n1=n;
        while (n1 > 0) {
            int a = n1 % 10;
            if (a != 0) res = res *10 + a  ;
            n1 /= 10;
        }

        long long finalRes = 0;
        while (res > 0) {
            finalRes = finalRes * 10 + res % 10;
            res /= 10;
        }

        return finalRes;
    }
};