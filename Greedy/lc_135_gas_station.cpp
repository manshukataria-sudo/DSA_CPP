#include <iostream>
#include <vector>
using namespace std;
// https://leetcode.com/problems/gas-station/?envType=problem-list-v2&envId=greedy

/*
TC = O(N)
SC = O(1);
*/
class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while (i < n) {
            if (cost[i] <= gas[i]) {
                int start = i;
                int tank_capacity = gas[i];
                int curr = i;
                while (cost[curr] <= tank_capacity) {
                    tank_capacity -= cost[curr];
                    curr++;
                    if (curr == n) {
                        curr = 0;
                    }
                    tank_capacity += gas[curr];
                    if (curr == start) {
                        return start;
                    }
                }
                if (curr < start) {
                    return -1;
                } else {
                    i = curr - 1;
                }
            }
            i++;
        }
        return -1;
    }
};