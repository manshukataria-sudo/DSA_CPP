#include <iostream>
#include <vector>
using namespace std;
string f(vector<int>& piles) {
    int a = piles[0];
    int b = piles[1];
    if ((a + b) % 3 == 0 && 2 * min(a, b) >= max(a, b)) {
        return "YES";
    }
    return "NO";
}
int main() {
    int sets;
    cin >> sets;

    vector<vector<int>> coins(sets, vector<int>(2));
    for (int i = 0; i < sets; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> coins[i][j];
        }
    }

    for (int i = 0; i < sets; i++) {
        cout << f(coins[i]) << "\n";
    }
}