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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL){
            return true;
        }

        if(root == NULL){
            return false;
        }

        if(sameTree(root, subRoot)){
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool sameTree(TreeNode* root, TreeNode* subRoot){
        if(root == NULL && subRoot == NULL){
            return true;
        }

        if(root && subRoot && root->val == subRoot->val){
            return sameTree(root->right, subRoot->right) && sameTree(root->left, subRoot->left);
        } else {
            return false;
        }
    }
};
