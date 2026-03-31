#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int threshold = a[k-1];
    int count = 0;

    for(int i = 0; i < n; i++) if(a[i] >= threshold && a[i] > 0) count++;

    cout << count << "\n";
}