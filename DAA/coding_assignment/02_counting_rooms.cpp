#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<bool>>& visited, int sR, int sC, vector<vector<char>>& map) {
    int rows = visited.size();
    int cols = visited[0].size();

    int pR[] = {-1, 1, 0, 0};
    int pC[] = {0, 0, -1, 1};

    visited[sR][sC] = true;

    for (int i = 0; i < 4; i++) {
        int nR = pR[i] + sR;
        int nC = pC[i] + sC;

        if (nR >= 0 && nR < rows && nC >= 0 && nC < cols && !visited[nR][nC] &&
            map[nR][nC] == '.') {
            dfs(visited, nR, nC, map);
        }
    }
}
int main() {
    int n, m;
    cout << "Enter the No. of Rows : ";
    cin >> n;
    cout << "Enter the no. of COls : ";
    cin >> m;

    cout << "Enter the map : ";
    vector<vector<char>> map(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int rooms = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && map[i][j] == '.') {
                rooms++;
                dfs(visited, i, j, map);
            }
        }
    }
    cout << rooms << "\n";
}

// Each character is either . (floor) or # (wall).