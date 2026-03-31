#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;

    if(islower(s[0])) s[0] = toupper(s[0]);
    cout << s << "\n";
}