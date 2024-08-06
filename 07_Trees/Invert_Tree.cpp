// Invert a Binary Tree
// You are given the root of a binary tree root.Invert the binary tree and return its root.

#include <iostream>

using namespace std;

struct TreeNode{ // Definition for a binary tree node.
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    TreeNode *invertTree(TreeNode *root){
        if (root == NULL){
            return NULL;
        }
        TreeNode* node = new TreeNode(root->val); // Pass in root->val
        node->right = invertTree(root->left);
        node->left = invertTree(root->right);
        return node;
    }
};
