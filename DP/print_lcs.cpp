#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


// https://www.hackerrank.com/challenges/linkedin-practice-dynamic-programming-lcs/problem


int main() {
    int n, m;
    cin >> n >> m;

    vector<int> nums1(n);
    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }

    vector<int> nums2(m);
    for (int j = 0; j < m; j++) {
        cin >> nums2[j];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    vector<int> lcs;

    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (nums1[i - 1] == nums2[j - 1]) {
            lcs.push_back(nums1[i - 1]);
            i--;
            j--;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
    }

    reverse(lcs.begin(), lcs.end());
    for (int i = 0; i < lcs.size(); i++) {
        cout << lcs[i] << " ";
    }
}
