#include <iostream>
#include <vector>

using namespace std;

/*
TC = O(N)
SC = O(1)
*/

// https://leetcode.com/problems/break-a-palindrome/description/
class Solution {
   public:
    string breakPalindrome(string palin) {
        int n = palin.size();
        if (n == 1) {
            return "";
        }
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (n % 2 == 1 && i == n / 2) {
                continue;
            }
            if (palin[i] > 'a') {
                palin[i] = 'a';
                return palin;
            }
            if (i == n - 1) {
                palin[i] = (char)((int)palin[i] + 1);
                return palin;
            }
        }
        return "";
    }
};