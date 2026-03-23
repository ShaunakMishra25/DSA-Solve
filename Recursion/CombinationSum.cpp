#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;

        solve(candidates, 0, 0, target, curr, res);
        return res;
    }

    void solve(vector<int>& candidates, int index, int sum,  int k,  vector<int>& curr, vector<vector<int>>& res){
        if(sum  == k){
            res.push_back(curr);
            return;
        }
        if(sum > k){
            return;
        }
        if(index == candidates.size()){
            return;
        }
        curr.push_back(candidates[index]);

        solve(candidates, index , sum + candidates[index], k, curr, res);

        curr.pop_back();

        solve(candidates, index + 1, sum, k, curr, res);
        return;
        
    }
};