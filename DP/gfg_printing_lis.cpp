#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
* -TC = O(n^2)
SC = O(n)
*/

// https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1
class Solution {
   public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        int n = arr.size();

        vector<int> dp(n, 1);

        vector<int> prev(n, -1);

        for (int i = 1; i < n; i++) {
            int max_idx = i;
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    if (max_idx == i || dp[j] > dp[max_idx]) {
                        max_idx = j;
                    }
                }
            }
            if (max_idx != i) {
                prev[i] = max_idx;
                dp[i] = dp[max_idx] + 1;
            }
        }

        vector<int> lis;
        int max_idx = 0;
        for (int i = 1; i < n; i++) {
            if (dp[max_idx] < dp[i]) {
                max_idx = i;
            }
        }

        while (max_idx != -1) {
            lis.push_back(arr[max_idx]);
            max_idx = prev[max_idx];
        }

        reverse(lis.begin(), lis.end());
        return lis;
    }
};