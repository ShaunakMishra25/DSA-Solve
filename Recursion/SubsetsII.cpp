#include <bits/stdc++.h>
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> current;
        sort(nums.begin(), nums.end()); 
        solve(nums, 0, current, res);
        return res;
    }
    void solve(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& res){
        if(index == nums.size()){
            res.push_back(current);
            return;
        }
        int next = index + 1;
        while(next < nums.size() && nums[next] == nums[index]) next++;

        solve(nums, next, current, res);
        current.push_back(nums[index]);

        solve(nums, index + 1, current, res);
        current.pop_back();
        return;
    }
};