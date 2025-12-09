import java.util.HashMap;

public class FruitIntoBaskets {
 public static void main(String[] args) {
    Solution s1 = new Solution();
    int[] fruits = {1,2,1,2,3};
    System.out.println(s1.totalFruit(fruits));
 }   
}
class Solution {
    public int totalFruit(int[] fruits) {
        HashMap<Integer, Integer> f = new HashMap<>();
        int n = fruits.length;
        int low = 0, res = 0;
        
        for(int high = 0; high < n; high++){
            
            f.put(fruits[high], f.getOrDefault(fruits[high], 0)+1);

            while(f.size()>2){
                int leftFruit = fruits[low];
                int updatedFreq = f.getOrDefault(leftFruit ,0) - 1;
                
                if(updatedFreq == 0) f.remove(leftFruit);
                else f.put(leftFruit, updatedFreq);
                
                low++;
            }
            res = Math.max(res, high-low+1);
        }

        return res;
    }
}