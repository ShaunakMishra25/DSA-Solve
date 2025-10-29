int solve(int arr[], int i, int j){
    if(i>=j) return 0;
    int mini = INT_MAX;
    for(int k=i; k<j; k++){
        int temp = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        mini = min(mini, temp);
    }
    return mini;

}