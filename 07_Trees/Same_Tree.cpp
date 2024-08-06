/* Same Binary Tree
Given the roots of two binary trees p and q, return true if the trees are equivalent, otherwise return false.
Two binary trees are considered equivalent if they share the exact same structure and the nodes have the same values. */

#include <iostream>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){ // !p and p == NULL are same thing
            return true;
        }

        if(p && q && p->val == q->val){
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        } else {
            return false;
        }
    }
};