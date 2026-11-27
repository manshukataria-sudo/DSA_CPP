#include <iostream>
#include <vector>

using namespace std;

//   Definition for a binary tree node.
/*
TC = O(n)
SC = O(n)
*/
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    void f(TreeNode* root, vector<int>& inorder) {
        if (!root) {
            return;
        }
        f(root->left, inorder);
        inorder.push_back(root->val);
        f(root->right, inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        f(root, inorder);

        int i = 0, j = inorder.size() - 1;
        while (i < j) {
            int sum = inorder[i] + inorder[j];
            if (sum == k) {
                return true;
            } else if (sum < k) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
};