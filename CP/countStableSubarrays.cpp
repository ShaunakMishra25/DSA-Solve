#include <vector>
using namespace std;
class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        long long n = capacity.size();
        long long left[n], right[n];
        left[0] = 0;
        right[n - 1] = n - 1;
        for (int i = 1; i < n; i++) {
            if (capacity[i] < capacity[left[i - 1]]) {
                left[i] = i;
            } else {
                left[i] = left[i - 1];
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (capacity[i] < capacity[right[i + 1]]) {
                right[i] = i;
            } else {
                right[i] = right[i + 1];
            }
        }
        long long res = 0;
        for (int i = 0; i < n; i++) {
            if (left[i] <= right[i]) {
                res += right[i] - left[i] + 1
                ;
            }
        }
        return res;
    
    }
};