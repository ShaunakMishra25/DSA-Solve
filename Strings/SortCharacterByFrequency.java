package Strings;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class SortCharacterByFrequency{
    public static void main(String [] args){

    }
}

class Solution {
    public String frequencySort(String s) {
        StringBuilder sb = new StringBuilder();
        HashMap<Character, Integer> freq = new HashMap<>();

        for(char ch: s.toCharArray()){
            freq.put(ch, freq.getOrDefault(ch, 0)+1);
        }
        
        int maxFreq = 0;
        for(int f: freq.values()){
            maxFreq = Math.max(maxFreq, f);
        }

        List <Character>[] Buckets = new List[maxFreq+1];
        for(int i=0;i <= maxFreq; i++){
            Buckets[i] = new ArrayList<>();
        } 

        for(char ch: freq.keySet()){
            int f = freq.get(ch);
            Buckets[f].add(ch);
        }


        for(int f= maxFreq; f>0; f--){
            for(char ch : Buckets[f]){
                for(int i = 0; i<f; i++){
                    sb.append(ch);
                }
            }
        }

        return sb.toString();
    }
}
