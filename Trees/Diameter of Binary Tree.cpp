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
        return 1+max(height(root->left),height(root->right));
    }
    pair<int,int> fast(TreeNode *root)
    {
        if(root==0)
        {
            pair<int,int> p=make_pair(0,0);
            return p;
        }
        pair<int,int> left=fast(root->left);
        pair<int,int> right=fast(root->right);
        int op1=left.first,op2=right.first;
        int op3=left.second+right.second;
        pair<int,int> p;
        p.first=max(op1,max(op2,op3));
        p.second=1+max(left.second,right.second);
        return p;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        return fast(root).first;
        
    }
};
