/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root,p,q);
    }

    TreeNode *helper(TreeNode *root,TreeNode *p,TreeNode *q){
        if (root==nullptr) return nullptr;

        if (root==p || root==q) return root;
        
        TreeNode *leftN=helper(root->left,p,q);
        TreeNode *rightN=helper(root->right,p,q);

        if (leftN && rightN) return root;
        else if (leftN) return leftN;
        else if (rightN) return rightN;
        return nullptr;
    }
};