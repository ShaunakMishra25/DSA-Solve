#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> current(n, 0);
        int ops = 0;

        // While current != target
        while (true) {
            bool done = true;
            for (int i = 0; i < n; i++) {
                if (current[i] != a[i]) {
                    done = false;
                    break;
                }
            }
            if (done) break;

            // Smash step: find elements we need to reset
            bool smashed = false;
            for (int i = 0; i < n; i++) {
                if (current[i] > a[i]) {
                    smashed = true;
                    current[i] = 0;
                }
            }
            if (smashed) {
                ops++;
                continue; // apply smash first
            }

            // Increase step: increase by min positive difference
            int min_inc = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (current[i] < a[i]) {
                    min_inc = min(min_inc, a[i] - current[i]);
                }
            }
            for (int i = 0; i < n; i++) {
                current[i] += min_inc;
            }
            ops++;
        }

        cout << ops << "\n";
    }
}
