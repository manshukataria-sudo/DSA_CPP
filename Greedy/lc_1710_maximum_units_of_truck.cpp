#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// https://leetcode.com/problems/maximum-units-on-a-truck/description/
class Solution {
   public:
/* TC = O(nlogn)  SC = O(sort) */
    int maximumUnits(vector<vector<int>>& nums, int truckSize) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), [](vector<int>& a, vector<int>& b) { return a[1] > b[1]; });

        int units = 0;
        int i = 0;
        while (i < n && truckSize) {
            if (truckSize >= nums[i][0]) {
                units += (nums[i][0] * nums[i][1]);
                truckSize -= nums[i][0];
                i++;
            } else {
                units += nums[i][1];
                truckSize--;
            }
        }
        return units;
    }
};