#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    string repeatLimitedString(string s, int limit) {
        int n = s.size();
        unordered_map<char, int> freq;
        for (int i = 0; i < n; i++) {
            freq[s[i]]++;
        }

        priority_queue<char> heap;
        for (auto ele : freq) {
            heap.push(ele.first);
        }

        string ans = "";
        while (heap.size()) {
            char temp = heap.top();
            heap.pop();
            int count = min(limit, freq[temp]);
            for (int i = 1; i <= count; i++) {
                ans += temp;
                freq[temp]--;
            }

            if (freq[temp] > 0) {
                if (heap.size()) {
                    char sec_lar = heap.top();
                    heap.pop();
                    ans += sec_lar;
                    freq[sec_lar]--;
                    if (freq[sec_lar]) {
                        heap.push(sec_lar);
                    }
                    heap.push(temp);
                } else {
                    return ans;
                }
            }
        }

        return ans;
    }
};