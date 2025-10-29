class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int sum=0, maxLen=0;
        unordered_map <int, int> preInd;
        
        for(int i = 0; i<n; i++){
            sum+=arr[i];
            
            if(sum==k) maxLen = i+1;
            
            if(preInd.find(sum-k) != preInd.end())
            maxLen = max(maxLen, i - preInd[sum-k]);
            
            if(preInd.find(sum)==preInd.end())
            preInd[sum]=i;
        }
        return maxLen;
    }
};