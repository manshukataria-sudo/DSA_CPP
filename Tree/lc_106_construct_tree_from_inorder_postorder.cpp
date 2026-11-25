#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//  * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
class Solution {
   public:
    TreeNode* f(vector<int>& inorder, vector<int>& postorder, int a, int b, int c, int d,
                unordered_map<int, int>& map) {
        if (a > b) {
            return NULL;
        }
        if (a == b) {
            return new TreeNode(inorder[a]);
        }

        TreeNode* root = new TreeNode(postorder[d]);

        int idx = map[postorder[d]];

        root->right = f(inorder, postorder, idx + 1, b, c + idx - a, d - 1, map);
        root->left = f(inorder, postorder, a, idx - 1, c, c + idx - a - 1, map);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> map;

        for (int i = 0; i < n; i++) {
            map[inorder[i]] = i;
        }
        return f(inorder, postorder, 0, n - 1, 0, n - 1, map);
    }
};