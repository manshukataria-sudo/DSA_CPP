#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// https://leetcode.com/problems/merge-intervals/description/

/*
TC = O(nlogn)
SC = O(sort) + storing answer
*/

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            vector<int> curr = intervals[i];

            if (curr[0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], curr[1]);
            } else {
                ans.push_back(curr);
            }
        }
        return ans;
    }
};