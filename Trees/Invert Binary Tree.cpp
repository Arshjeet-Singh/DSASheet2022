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
    TreeNode* invertTree(TreeNode* root) {
        if(root==0 || (root->left==0 && root->right==0))
        {
            return root;
        }
        TreeNode *l=invertTree(root->left);
        TreeNode *r=invertTree(root->right);
        // TreeNode *temp=root->left;
        root->left=r;
        root->right=l;
        return root;
    }
};
