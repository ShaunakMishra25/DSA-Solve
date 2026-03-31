#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    int count = 0;

    unordered_set<char> st(s.begin(), s.end());

    cout << (st.size() % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!") << "\n";
    
}