class Solution {
  public:
    int t[101][101];
    
    int solve(vector<int>& arr, int i , int j){
        if(i>=j) return 0;
        
        if(t[i][j]!=-1) return t[i][j];
        
        int mn=INT_MAX;
        
        for(int k =i;k<=j-1;k++){
            int temp=solve(arr,i,k)+
                solve(arr,k+1,j)+
                arr[i-1]*arr[k]*arr[j];
            
            mn=min(mn,temp);
        }
        return t[i][j]=mn;
        
    }
  
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        memset(t, -1, sizeof(t));
        return solve(arr, 1, n - 1);
    }
};