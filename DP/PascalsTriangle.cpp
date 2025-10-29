#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;

    for(int i = 0; i < numRows; i++) {
        vector<int> row(i + 1, 1); // initialize row with 1s

        // fill middle elements
        for(int j = 1; j < i; j++) {
            row[j] = result[i-1][j-1] + result[i-1][j];
        }

        result.push_back(row);
    }

    return result;
}

int main() {
    int numRows = 5;
    vector<vector<int>> pascal = generate(numRows);

    for(auto &row : pascal) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
