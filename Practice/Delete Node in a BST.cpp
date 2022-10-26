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
    TreeNode * getmin(TreeNode * root)
    {
        while(root->left!=0)
        {
            root=root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==0)
        {
            return root;
        } 
        if(root->val==key)
        {
            //0 child
            if(root->left==0 && root->right==0)
            {
                delete root;
                return 0;
            }
            if(root->left==0 && root->right!=0)
            {
                TreeNode *temp=root->right;
                delete root;
                return temp;
            }
            if(root->right==0 && root->left!=0)
            {
                TreeNode *temp=root->left;
                delete root;
                return temp;                
            }
            if(root->left!=0 && root->right!=0)
            {
                TreeNode *minnode=getmin(root->right);
                int data1=minnode->val;
                root->val=data1;
                root->right=deleteNode(root->right, data1);
                return root;
            }
        }
        else if(root->val>key)
        {
            root->left=deleteNode(root->left,key);
            return root;
        }
        else
        {
            root->right=deleteNode(root->right,key);
            return root;
        }
        return root;
    }
};
