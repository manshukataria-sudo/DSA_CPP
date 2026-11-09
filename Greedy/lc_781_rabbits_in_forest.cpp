#include <iostream>
#include <unordered_map>
#include <vector>
#include <math.h>

// https://leetcode.com/problems/rabbits-in-forest/

/* 
TC = O(n)
SC = O(n)
 */
using namespace std;
class Solution {
   public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[answers[i]]++;
        }

        int ans = 0;

        for (auto ele : freq) {
            if (ele.second <= ele.first + 1) {
                ans += (ele.first + 1);
            } else {
                double temp = ceil((double)ele.second / (ele.first + 1));
                ans += ((ele.first + 1) * temp);
            }
        }

        return ans;
    }
};