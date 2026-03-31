#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> res;
        vector<int> curr;

        solve(nums, k, n, 0, 0, 0, curr, res);
        return res;
    }
    void solve(vector<int>& nums, int k, int n , int index, int count, int sum, vector<int> curr, vector<vector<int>> res){

        if(sum == n && k == count){
            res.push_back(curr);
        }
        if(sum > n || count > k || index >= nums.size()){
            return;
        }

        curr.push_back(nums[index]);

        solve(nums, k, n, index + 1, count + 1, sum + nums[index], curr, res);

        solve(nums, k, n, index + 1, count, sum, curr, res);
        curr.pop_back();

        return;
    }
};

/*


class Solution {
    public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;
        
        solve(n, k, 1, 0, curr, res);
        return res;
    }
    void solve(int n,  int k, int start, int sum, vector<int>& curr, vector<vector<int>>& res ){
        if(sum == n && curr.size() == k){
            res.push_back(curr);
            return;
        }
        
        if(sum > n || curr.size() > k || start > 9){
            return;
        }
        
        for(int i = start; i <= 9; i++){
            curr.push_back(i);
            solve(n, k, i + 1, sum + i, curr, res);
            curr.pop_back();
        }
        
        return;
        
    }
};
*/