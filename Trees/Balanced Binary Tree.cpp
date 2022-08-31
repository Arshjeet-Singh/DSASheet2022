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
    int height(TreeNode *root)
    {
        if(root==0)
        {
            return 0;
        }
        int lh=height(root->left);
        if(lh==-1)
        {
            return -1;
        }
        int rh=height(root->right);
        if(rh==-1)
        {
            return -1;
        }
        if(abs(lh-rh)>1)
        {
            return -1;
        }
        return 1+max(lh,rh);
        // return 1+max(height(root->left),height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        // o(n) change height function 
        if(height(root)==-1)
        {
            return false;
        }
        else
        {
            return true;
        }
        //o(n^2)        
        // if(root==0)
        // {
        //     return true;
        // }
        // if(abs(height(root->left)-height(root->right))<=1)
        // {
        //     return isBalanced(root->left)&&isBalanced(root->right);
        // }
        // else
        // {
        //     return false;
        // }
    }
};
