#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

        int count = 0;
        int i = 0;

        while (i < n) {
            int start_dist = points[i][0];
            int end_dist = points[i][1];
            i += 1;

            while (i < n && points[i][0] < end_dist) {
                start_dist = max(start_dist, points[i][0]);
                end_dist = min(end_dist, points[i][1]);
                i++;
            }
            count += 1;
        }

        return n - count;
    }
};