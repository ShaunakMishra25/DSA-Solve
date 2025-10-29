#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int,int> freq;
        for(int i=0; i< nums.size(); i++){
            freq[nums[i]]++;
            if(freq[nums[i]] % k == 0){
                sum += nums[i];
            }
        }
        return sum;
    }
};