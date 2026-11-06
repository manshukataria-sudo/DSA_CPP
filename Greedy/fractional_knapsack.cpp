#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;  // no. of items
    vector<vector<int>> info(2, vector<int>(n));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> info[i][j];
        }
    }

    sort(info.begin(), info.end(), []);
}