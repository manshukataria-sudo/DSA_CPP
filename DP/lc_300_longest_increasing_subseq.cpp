#include <iostream>
#include <vector>

using namespace std;

/* 
TC = O(n^2)
SC = O(n)
*/

// https://leetcode.com/problems/longest-increasing-subsequence/
class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 1; i < n; i++) {
            int temp = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    temp = max(temp, dp[j] + 1);
                }
            }
            dp[i] = temp;
            ans = max(ans, temp);
        }
        return ans;
    }
};