package MergeIntervals;

import java.util.ArrayList;
import java.util.List;

public class IntervalListIntersection {
    
}
class Solution {
    public int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
        int i = 0, j =0;
        List<int[]> result = new ArrayList<>();
        while(i < firstList.length && j < secondList.length){
            int start1 = firstList[i][0];
            int end1 = firstList[i][1];
            int start2 = secondList[j][0];
            int end2 = secondList[j][1];

            int s = Math.max(start1, start2);
            int e = Math.min(end1, end2);
            if(e >= s){
                result.add(new int[]{s,e});
            }
            if(end1<=end2)i++;
            else j++;
        }

        return result.toArray(new int[result.size()][]);
    }
}