public class PowerOf2 {
    public static void main(String[] args) {
        Solution s1 = new Solution();
        System.out.println(s1.powerof2(16));
    }
}

class Solution {
    public boolean powerof2(int n){
        if(n<=0) return false;
        if(n==1) return true;
        if(n%2 != 0) return false;
        return powerof2(n/2);
    }
}
