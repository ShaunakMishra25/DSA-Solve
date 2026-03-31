#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b; cin >> a >> b;
    int count = 0;

    while(a <= b){
        count +=1;
        a *= 3; b *= 2;
    }
    cout << count << "\n";
}