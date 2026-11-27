#include <iostream>
#include <vector>

using namespace std;

// Definition for Node
// https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1

/* 
TC = O(height)
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
    int minValue(Node *root) {
      // code here
      if (!root) {
        return -1;
      }
      while (root->left) {
        root = root->left;
      }
      return root -> data;
    }
};