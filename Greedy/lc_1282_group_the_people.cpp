#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
/* 
TC = O(n)
SC = O(n)
 */
class Solution {
   public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        unordered_map<int, vector<int>> map;

        for (int i = 0; i < n; i++) {
            map[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> ans;
        for (auto ele : map) {
            if (ele.second.size() == ele.first) {
                ans.push_back(ele.second);
            } else {
                int i = 0;
                while (i < ele.second.size()) {
                    vector<int> helper(ele.first);
                    int j = 0;
                    while (j < ele.first) {
                        helper[j++] = ele.second[i++];
                    }
                    ans.push_back(helper);
                }
            }
        }

        return ans;
    }
};