#include <iostream>
#include <vector>
using namespace std;
void f(vector<int>& nums, vector<vector<int>>& ans, vector<int>& candidates, int target, int i) {
    if (target <= 0) {
        if (target == 0)
            ans.push_back(nums);
        return;
    }

    if (i < 0) {
        return;
    }

    if (target >= candidates[i]) {
        nums.push_back(candidates[i]);
        f(nums, ans, candidates, target - candidates[i], i);
        nums.pop_back();
    }
    f(nums, ans, candidates, target, i - 1);
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int n = candidates.size();

    vector<int> nums;
    vector<vector<int>> ans;
    f(nums, ans, candidates, target, n - 1);
    return ans;
}

int main() {
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    vector<vector<int>> ans = combinationSum(nums, target);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}

// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.
// Example 2:

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]
// Example 3:

// Input: candidates = [2], target = 1
// Output: []

// Constraints:

// 1 <= candidates.length <= 30
// 2 <= candidates[i] <= 40
// All elements of candidates are distinct.
// 1 <= target <= 40