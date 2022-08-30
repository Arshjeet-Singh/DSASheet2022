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
    int helper(TreeNode *root,bool isleft)
    {
        if(root==0)
        {
            return 0;
        }
        if(root->left==0 && root->right==0)
        {
            if(isleft)
            {
                return root->val;
            }
            else
            {
                return 0;
            }
        }
        return helper(root->left,true)+helper(root->right,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root,false);
        // if(root==0)
        // {
        //     return 0;
        // }
        // queue<TreeNode *>q;
        // q.push(root);
        // TreeNode *prev=0;
        // int ans=0;
        // while(!q.empty())
        // {
        //     TreeNode *a=q.front();
        //     int b=a->val;
        //     if(a->left==0 && a->right==0)
        //     {
        //         if(prev!=0 && prev->left==a)
        //         {
        //             ans+=a->val;
        //         }
        //     }
        //     q.pop();
        //     if(a->left!=0)
        //     {
        //         q.push(a->left);
        //     }
        //     if(a->right!=0)
        //     {
        //         q.push(a->right);
        //     }
        //     prev=a;
        // }
        // return ans;
    }
};
