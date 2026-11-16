#include <algorithm>
#include <iostream>
#include <vector>
// https://leetcode.com/problems/bag-of-tokens/

/* 
TC = O(N)
SC = O(1)
*/
using namespace std;
class Solution {
   public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        if (!n || power < tokens[0]) {
            return 0;
        }

        int score = 0;
        int i = 0, j = n - 1;

        while (i <= j) {
            if (power >= tokens[i]) {
                power -= tokens[i];
                score++;
                i++;
            } else {
                if (i <= n - 1 && score > 0 && power + tokens[j] >= tokens[i]) {
                    power = power + tokens[j] - tokens[i];
                    i++;
                    j--;
                } else {
                    return score;
                }
            }
        }
        return score;
    }
};