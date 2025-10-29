#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std;using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for(int i=0; i<n; i++){
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i]-minPrice);
        }
        
        return maxProfit;
    }
};

int main(){
    Solution sol;
    vector<int> prices = {7,1,5,3,6,4};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}