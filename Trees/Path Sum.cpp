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
    bool helper(TreeNode* root,int s, int targetSum)
    {
        if(root==0)
        {
            return false;
        }
        // if(targetSum==0)
        // {
        //      return true;
        // }
        bool b1=false,b2=false;
       s+=root->val;
        if(root->left==0 && root->right==0)
        {
            cout<<s<<endl;
            if(targetSum==s)
            {
                return true;    
            }
            
        }
        if(root->left!=0)
        {
              b1=helper(root->left,s,targetSum);
        }
        if(root->right!=0)
        {
             b2=helper(root->right,s,targetSum);
        }
        return b1||b2;
        // return true;
        // return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root,0,targetSum);
        
    }
};
