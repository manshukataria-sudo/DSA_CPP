#include <iostream>
#include <vector>

using namespace std;
// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
class Solution {
   public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();

        int i = 0;
        int ans = 0;
        while (i < n) {
            int j = i;
            int sum = 0;
            int max_time = -1;

            while (j < n && colors[i] == colors[j]) {
                max_time = max(max_time, neededTime[j]);
                sum += neededTime[j];
                j++;
            }

            ans += (sum - max_time);
            i = j;
        }
        return ans;
    }
};