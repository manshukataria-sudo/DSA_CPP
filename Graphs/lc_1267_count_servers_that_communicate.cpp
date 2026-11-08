#include <iostream>
#include <vector>
using namespace std;
// https://leetcode.com/problems/count-servers-that-communicate/?envType=daily-question&envId=2026-11-08
/* 
TC = O(m * n)
SC = O(m + n)
*/
class Solution {
   public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> row_count(m, 0);
        vector<int> col_count(n, 0);
        int total_servers = 0;

        // counting total_servers and servers in each row and column
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    total_servers++;
                    row_count[i]++;
                    col_count[j]++;
                }
            }
        }

        // counting isolated_servers
        int isolated = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    if (row_count[i] == 1 && col_count[j] == 1) {
                        isolated++;
                    }
                }
            }
        }
        return total_servers - isolated;
    }
};