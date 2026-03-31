#include <bits/stdc++.h>
using namespace std;

int digitSum(int y) {
    int sum = 0;
    while (y > 0) {
        sum += y % 10;
        y /= 10;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long x;
        cin >> x;

        int count = 0;

        // Check only in range [x, x + 100]
        for (long long y = x; y <= x + 100; y++) {
            if (y - digitSum(y) == x) {
                count++;
            }
        }

        cout << count << "\n";
    }

    return 0;
}