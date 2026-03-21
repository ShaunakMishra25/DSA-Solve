class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> res;
            vector<int> path;
            backtrack(nums, 0, path, res);
            return res;
        }
        void backtrack(vector<int>& nums, int start, )
    };