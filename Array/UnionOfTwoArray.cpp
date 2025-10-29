class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
       for (int x : a ) s.insert(x);
       for (int x: b) s.insert(x);

       vector<int> ans(s.begin(),s.end());
       return ans;
    }
};      
    }
};