class Solution {
public:
    void f(vector<vector<int>>& ans, vector<int>& cand, vector<int>& ds,
           int target, int curr) {
        if (target <= 0 || curr >= cand.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        int tester = INT_MIN;
        for (int i = curr; i < cand.size(); i++) {
            if (tester != cand[i]) {
                ds.push_back(cand[i]);
                f(ans, cand, ds, target - cand[i], i + 1);
                ds.pop_back();
            }
            tester = cand[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(), cand.end());
        vector<vector<int>> ans;
        vector<int> ds;
        f(ans, cand, ds, target, 0);
        return ans;
    }
};