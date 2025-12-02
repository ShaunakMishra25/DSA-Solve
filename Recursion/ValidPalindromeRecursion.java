public class ValidPalindromeRecursion {
    public static void main(String[] args) {
        
    }
}

class Solution {
    public boolean isPalindrome(String s) {
        int i = 0, j =s.length()-1;
        return pali(i, j, s);
    }   
    public static boolean pali(int i, int j, String s){
        
        while(i< j && !Character.isLetterOrDigit(s.charAt(i))){
            i++;
        }

        while(i< j && !Character.isLetterOrDigit(s.charAt(j))){
            j--;
        }

        if(i>=j) return true;

        if(Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(j))) return false;
        return pali(i+1, j-1, s);
    }  
}