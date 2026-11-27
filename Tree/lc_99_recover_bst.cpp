#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//   Definition for a binary tree node.
/*
TC = O(nlogn)
SC = O(n)
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
    void f(TreeNode* root, vector<int>& inorder) {
        if (!root) {
            return;
        }
        f(root->left, inorder);
        inorder.push_back(root->val);
        f(root->right, inorder);
    }
    void recover(TreeNode* root, vector<int>& inorder, int& i) {
        if (!root) {
            return;
        }
        recover(root->left, inorder, i);
        root->val = inorder[i];
        i += 1;
        recover(root->right, inorder, i);
    }
    void recoverTree(TreeNode* root) {
        vector<int> inorder;
        f(root, inorder);
        sort(inorder.begin(), inorder.end());
        int i = 0;
        recover(root, inorder, i);
    }
};