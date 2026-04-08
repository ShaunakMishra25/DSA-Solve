#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n;cin >> n;
        string s; cin >> s;

        string seg = "....";
        if ( s.contains(seg)) cout << 2 << "\n";
        else{
            int count = 0;
            for(int i = 0; i < n; i++){
                if(s[i] == '.') count++;
            }
            if(count == 1) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        
    }


}