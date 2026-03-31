#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int num = 0;
    while(n--){
        string s; cin >> s;
        if(s[1] == '+') num++;
        else num--;
    }
    cout << num << "\n";

}