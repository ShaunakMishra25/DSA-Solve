#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            int x; cin >> x;
            if(x == 1){
                cout << abs(i - 2) + abs(j - 2) << "\n";
                return 0;
            }
        }
    }
}