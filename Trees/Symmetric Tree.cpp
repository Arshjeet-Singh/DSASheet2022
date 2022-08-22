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
    bool helper(TreeNode *left,TreeNode *right)
    {
        if(left==0 || right==0)
        {
            return left==right;
        }
        if(left->val!=right->val)
        {
            return false;
        }
        else
        {
            return helper(left->left,right->right)&&helper(left->right,right->left);
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(root==0 || helper(root->left,root->right))
        {
            return true;
        }
        return false;
        // if(root->left->val ==root->right->val)
        // {
        //     return isSymmetric(root->left)&&isSymmetric(root->right);
        // }
        // else
        // {
        //     return false;
        // }
        
    }
};
