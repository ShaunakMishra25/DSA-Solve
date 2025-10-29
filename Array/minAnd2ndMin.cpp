#include <vector>
#include <climits>

class Solution {
  public:
    vector<int> minAnd2ndMin(vector<int> &arr) {
        // code here
        int n=arr.size();
        int min=INT_MAX, secMin=INT_MAX;
        for(int i=0;i<n;i++){
            if(arr[i]<min){
                secMin=min;
                min=arr[i];
            }
            else if(arr[i]<secMin && arr[i]!=min){
                secMin=arr[i];
            }
        }           
        if (secMin == INT_MAX) return  {-1};
        return {min, secMin};       
    }
};