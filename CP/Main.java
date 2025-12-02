import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int t = sc.nextInt();
        int arr[]= new int[t]; 
        for(int i=0;i<t;i++){
            arr[i] =sc.nextInt();
        }
        for(int i =0;i < t;i++){
            int c=-1;
            for(int j=i-1;j>=0;j++){
                if(arr[j]>arr[i]){
                    c=j+1;
                    break;
                }
            }
            System.out.println(c);
        }
    }
}
