/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int ans=0;
    int sumRootToLeaf(TreeNode* root) {
        helper(root,0);
        return ans;
    }
    void helper(TreeNode *root,int sum){
        if (root==nullptr) return ;

        sum=sum+root->val;

        if (root->left==nullptr && root->right==nullptr){
            ans+=sum;
            return;
        }
        helper(root->left,sum*2);
        helper(root->right,sum*2);
        return;
    }
};