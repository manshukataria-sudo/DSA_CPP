#include <iostream>
#include <vector>

using namespace std;
/*
TC = O(target)
SC = O(1)
 */

//  https://leetcode.com/problems/broken-calculator/
class Solution {
   public:
    int brokenCalc(int startValue, int target) {
        if (target <= startValue) {
            return startValue - target;
        }
        int count = 0;
        while (target != startValue) {
            if (target % 2 == 0 && target > startValue) {
                target /= 2;
            } else {
                target += 1;
            }
            count++;
        }
        return count;
    }
};