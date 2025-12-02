
import java.util.Scanner;
public class QuesA1{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int x = sc.nextInt();
        int y = sc.nextInt(); 
        int z = sc.nextInt(); 
        boolean found = false;

        for(int i = 0; i < 100; i++){
            if(x == y * z){
                found = true;
                break;
            }
            x++; y++;
        }
        System.out.println(found ? "Yes" : "No");
    }
}
class Solution {
    public void QuesA(int n) {
        Scanner sc = new Scanner(System.in);

        int x = sc.nextInt();
        int y = sc.nextInt(); 
        int z = sc.nextInt(); 
        boolean found = false;

        for(int i = 0; i < 100; i++){
            if(x == y * z){
                found = true;
                break;
            }
            x++; y++;
        }
        System.out.println(found ? "Yes" : "No");
    }
}
