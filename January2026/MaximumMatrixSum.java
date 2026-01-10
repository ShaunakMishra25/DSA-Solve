package January2026;

public class MaximumMatrixSum {
    
}
class Solution {
    public long maxMatrixSum(int[][] matrix) {
        long sumAbs = 0;
        int minAbs = Integer.MAX_VALUE;
        int negCount = 0;

        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[0].length; j++){
                int val = matrix[i][j];

                if(val < 0) negCount += 1;

                int absValue = Math.abs(val);
                sumAbs += absValue;

                minAbs = Math.min(absValue, minAbs);
            }

        }
        if(negCount % 2 != 0){
            sumAbs -= 2L * minAbs;
        }
        return sumAbs;
    }
}