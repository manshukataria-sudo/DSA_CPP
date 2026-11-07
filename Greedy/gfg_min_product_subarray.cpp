#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
TC = O(nlogn)
SC = O(1)
 */
class Solution {
   public:
    int minProd(vector<int>& arr) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());

        if (arr[0] >= 0) {
            return arr[0];
        }

        int count_neg = 0;
        int product = 1;
        int last_neg = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                count_neg++;
                last_neg = i;
            }
            if (arr[i] != 0) {
                product *= arr[i];
            }
        }

        return (count_neg % 2 == 1) ? product : product / arr[last_neg];
    }
};
