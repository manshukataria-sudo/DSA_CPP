#include <iostream>
#include <vector>

using namespace std;
/* 
TC = O(n)
SC = O(n)
 */

// https://leetcode.com/problems/insert-interval/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int n = intervals.size();

        // if size if zero return the array of newInterval directly
        if (n == 0) {
            return {newInterval};
        }

        vector<vector<int>> ans;

        int i = 1;
        bool added = false;
        // if newInterval have to be added before the first interval 
        if(newInterval[1] < intervals[0][0]){
            ans.push_back(newInterval);
            added = true;
        }
        ans.push_back(intervals[0]);
        while (i < n) {
            // if new interval can be merged, merge it
            if (!added && newInterval[0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], newInterval[1]);
                ans.back()[0] = min(ans.back()[0], newInterval[0]);
                added = true;
            } 
            // if new interval is not mergeing add it simply
            else if (!added && newInterval[0] <= intervals[i][0]) {
                ans.push_back(newInterval);
                added = true;
            } 
            // other interval's merging 
            else if (ans.back()[1] >= intervals[i][0]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
                i++;
            } else {
                ans.push_back(intervals[i]);
                i++;
            }
        }

        // if new interval have to be merged at the end
        if (!added && newInterval[0] <= ans.back()[1]) {
            ans.back()[1] = max(ans.back()[1], newInterval[1]);
            ans.back()[0] = min(ans.back()[0], newInterval[0]);
            added = true;
        }

        // if new interval have to be added the end
        if (!added) {
            ans.push_back(newInterval);
        }
        return ans;
    }
};