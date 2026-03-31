#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;

    string t; for(char c : s) if(isdigit(c)) t += c;
    sort(t.begin(), t.end());
    
    string ans = "";
    for(char c : t){ ans += c; ans += '+';}
    ans.pop_back();
    cout << ans << "\n";
}