class Solution{
public:
    vector<int> majorityElement(vector<int> &nums){
        int cand1 = INT_MAX, cand2 = INT_MAX;
        int cnt1 = 0, cnt2 = 0;

        for (int num : nums){
            if (num == cand1){
                cnt1++;
            }
            else if (num == cand2){
                cnt2++;
            }
            else if (cnt1 == 0){
                cand1 = num;
                cnt1 = 1;
            }
            else if (cnt2 == 0){
                cand2 = num;
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = cnt2 = 0;
        for (int num : nums){
            if (num == cand1)
                cnt1++;
            else if (num == cand2)
                cnt2++;
        }

        vector<int> res;

        if (cnt1 > nums.size() / 3){
            res.push_back(cand1);
        }
        if (cnt2 > nums.size() / 3){
            res.push_back(cand2);
        }
        return res;
    }
};