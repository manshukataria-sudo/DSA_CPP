#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// https://leetcode.com/problems/boats-to-save-people/
/*
TC = O(nlogn)
SC = O(Sort)
 */
class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();

        sort(people.begin(), people.end());
        int i = 0, j = n - 1;
        int boat_count = 0;
        while (i <= j) {
            if (people[i] + people[j] <= limit) {
                i++;
            }
            j--;
            boat_count++;
        }

        return boat_count;
    }
};