#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int minMeetingRooms(vector<int>& start, vector<int>& end) {
        // code here
        int n = start.size();
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int active_rooms = 0;
        int ans = 0;
        int i = 0, j = 0;
        while (i < n) {
            if (start[i] < end[j]) {
                active_rooms++;
                i++;
            } else {
                j++;
                active_rooms--;
            }
            ans = max(active_rooms, ans);
        }
        return ans;
    }
};
