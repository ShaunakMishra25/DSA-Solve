package SlowandFastPointer;

public class HappyNumber {
    public static void main(String[] args) {

    }
}

class Solution {
    public boolean isHappy(int n) {
        int slow = n, fast = n;
        while(fast != 1){
            slow = square(slow);
            fast = square(square(fast));
            
            if(slow == fast && slow != 1){
                return false;
            }
        }
        return true;
    }
    private int square(int n){
        int res = 0;
        while(n > 0){
            int a = n % 10;
            res += a * a;
            n = n / 10;
        }
        return res;
    }
}