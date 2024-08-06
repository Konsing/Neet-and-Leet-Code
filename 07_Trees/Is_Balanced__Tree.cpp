/* Balanced Binary Tree
Given a binary tree, return true if it is height-balanced and false otherwise.
A height-balanced binary tree is defined as a binary tree in which the left and right 
subtrees of every node differ in height by no more than 1 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root)[0] == 1;
    }
private:
    vector<int> dfs(TreeNode* root) {
        if (root == NULL) { // empty tree is balanced and has a height of 0
            return {1, 0};
        }

        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        bool balanced = left[0] == 1 && right[0] == 1 && abs(left[1] - right[1]) <= 1;
        int height = 1 + max(left[1], right[1]);

        return {balanced ? 1 : 0, height}; // first element is 1 if the current subtree is balanced and 0 otherwise
    }
};
