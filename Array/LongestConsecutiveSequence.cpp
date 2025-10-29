#include <vector>
#include <unordered_set>
#include <iostream> // Add this line to include iostream for cout
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int l_streak=0;
        for( int x : s){
            if(s.find(x-1)== s.end()){
                int curr=x;
                int len=1;
                while(s.find(curr+1)!= s.end()){
                    curr++;
                    len++;
                }
                l_streak= max(l_streak, len);
            }
        }
        return l_streak;
    }
};

int main(){
    Solution sol;
    vector<int> nums= {100,4,5,200,1,3,2};
    int res= sol.longestConsecutive(nums);
    cout<<res;
    return 0;
}