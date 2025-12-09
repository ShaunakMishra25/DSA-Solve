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
        int n = fruits.length;
        int low = 0, res = 0;
        HashMap<Integer, Integer> f = new HashMap<>();

        for(int high = 0; high < n; high++){
            int oldFreq = f.getOrDefault(fruits[high],0);
            int newFreq = oldFreq + 1;
            f.put(fruits[high], newFreq);
            
            while(f.size()>2){
                int oldFreqRe = f.getOrDefault(fruits[low], 0);
                int newFreqRe = oldFreqRe -1;

                if(newFreqRe == 0) f.remove(fruits[low]);
                else f.put(fruits[low], newFreqRe);
                low++;
            }
            res = Math.max(res, high-low+1);
        }
        return res;
    }
}