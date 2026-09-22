#include <iostream>
#include <vector>

using namespace std;
void subSeq(int i, vector<int>& ds, int target, vector<int>& nums) {
    if (i > nums.size() || target < 0) {
        return;
    }
    if (target == 0) {
        for (int i = 0; i < ds.size(); i++) {
            cout << ds[i] << " ";
        }
        cout << "\n";
        return;
    }
    ds.push_back(nums[i]);
    subSeq(i + 1, ds, target - nums[i], nums);

    ds.pop_back();
    subSeq(i + 1, ds, target, nums);
}
int main() {
    vector<int> nums = {1, 2, 1};
    int target = 2;
    vector<int> ds;
    subSeq(0, ds, target, nums);

    cout << '\n';
    return 0;
}