public class MirrorDistanceofanInteger {
    
}
class Solution {
    public int mirrorDistance(int n) {
        int num = n;
        int res = 0;
        while(n>0){
            int a = n % 10;
            res = res * 10 + a;
            n = n / 10;
        }
        return Math.abs(res - num);
    }
}