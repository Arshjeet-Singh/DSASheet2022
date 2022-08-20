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
    bool equal(TreeNode *root,TreeNode *subroot)
    {
        if(root==0 && subroot==0)
        {
            return true;
        }
        if((root==0 && subroot!=0) ||(subroot==0 && root!=0))
        {
            return false;
        }
        if(root->val==subroot->val)
        {
            return (equal(root->left,subroot->left)&&equal(root->right,subroot->right));
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==0 && subRoot!=0)
        {
            return false;;
        }
        if((root->left==0 || root->right==0) && subRoot==0)
        {
            return true;;
        }
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *a=q.front();
            q.pop();
            if(a->val==subRoot->val)
            {
                bool b=equal(a,subRoot);
                if(b)
                {
                    return b;
                }
            }
            if(a->left!=0)
            {
                q.push(a->left);
            }
            if(a->right!=0)
            {
                q.push(a->right);
            }
        }
        return false;
//         if(root->left->val==subRoot->val)
//         {
            
//         }
    }
};
