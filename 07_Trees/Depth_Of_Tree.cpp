/* Depth of Binary Tree
Given the root of a binary tree, return its depth.
The depth of a binary tree is defined as the number of nodes along the 
longest path from the root node down to the farthest leaf node. */

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// RECURSIVE DFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// BFS Solution
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;

        if(root != NULL){
            q.push(root);
        }

        int depth = 0;

        while(!q.empty()){
            int qsize = q.size();
            depth++;

            for(int i = 0; i < qsize; i++){ // remove entire row, add all children of row
                TreeNode* node = q.front();
                q.pop();

                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
        }

        return depth;
    }
};

// ITERATIVE DFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*, int>> stack;
        stack.push({root, 1});
        int deepest_depth = 0;

        while (!stack.empty()) {
            pair<TreeNode*, int> current = stack.top();
            stack.pop();
            TreeNode* node = current.first;
            int depth = current.second;

            if (node != NULL) {
                deepest_depth = max(deepest_depth, depth);
                stack.push({node->left, depth + 1});
                stack.push({node->right, depth + 1});
            }
        }
        return deepest_depth;
    }
};