#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//   Definition for a binary tree node.
/*
TC = O(n)
SC = O(Height)
*/

// https://leetcode.com/problems/recover-binary-search-tree/description/
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
    void f(TreeNode* root, TreeNode*& first, TreeNode*& second, TreeNode*& prev) {
        if (!root) {
            return;
        }
        f(root->left, first, second, prev);
        if (prev && prev->val > root->val) {
            if (!first) {
                first = prev;
                second = root;
            } else {
                second = root;
            }
        }
        prev = root;
        f(root->right, first, second, prev);
    }

    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL;
        TreeNode* first = NULL;
        TreeNode* second = NULL;

        f(root, first, second, prev);

        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};