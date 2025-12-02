public class countGoodNumbers {
    public static void main(String[] args) {
        Solution s1 = new Solution();
        System.out.println(s1.countGoodNumbers(50));
    }
}

class Solution {
    public int countGoodNumbers(long n) {

        return countGoodNumbersh(0,n);
    }
    private int countGoodNumbersh(int index, long n){
        if(index == n) return 1;

        
        return 1;
    }
}