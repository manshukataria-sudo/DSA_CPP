#include <iostream>
#include <vector>

using namespace std;

// Definition for Node
// https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

/*
TC = O(Height)
SC = O(1) 
*/
class Node {
   public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
   public:
    int findCeil(Node* root, int x) {
        // code here
        int ans = -1;
        while (root) {
            if (root->data == x) {
                return x;
            } else if (root->data > x) {
                ans = root->data;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return ans;
    }
};
