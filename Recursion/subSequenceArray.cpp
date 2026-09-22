#include <iostream>
#include <vector>

using namespace std;

void subSeq(vector<int>& nums, vector<int>& temp, int i, vector<vector<int>>& ans) {
    if (i >= nums.size()) {
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[i]);
    subSeq(nums, temp, i + 1, ans);
    temp.pop_back();
    subSeq(nums, temp, i + 1, ans);
}
int main() {
    vector<int> nums = {3, 2, 1};

    vector<vector<int>> ans;
    vector<int> temp;
    subSeq(nums, temp, 0, ans);

    cout << "\n";
    for (auto ele : ans) {
        for (int x : ele) {
            cout << x << " ";
        }
        cout << "\n";
    }
    cout << '\n';
    return 0;
}