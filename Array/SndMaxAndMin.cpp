class Solution {
public:
    vector<int> secondMinAndMax(vector<int> &arr) {
        int n = arr.size();
        int minVal = INT_MAX, secMin = INT_MAX;
        int maxVal = INT_MIN, secMax = INT_MIN;

        for (int i = 0; i < n; i++) {
            int x = arr[i];

            if (x < minVal) {
                secMin = minVal;
                minVal = x;
            } else if (x < secMin && x != minVal) {
                secMin = x;
            }

            if (x > maxVal) {
                secMax = maxVal;
                maxVal = x;
            } else if (x > secMax && x != maxVal) {
                secMax = x;
            }
        }

        if (secMin == INT_MAX) secMin = -1;
        if (secMax == INT_MIN) secMax = -1;

        return {secMin, secMax};
    }
};
