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
     if(root==0)
     {
         return 0;
     }
        if(root->val==p->val || root->val==q->val)
        {
            return root;
        }
        TreeNode* lans=lowestCommonAncestor( root->left,  p, q);
        TreeNode* rans=lowestCommonAncestor( root->right,  p, q);
        if(lans!=0 && rans!=0)
        {
            return root;
        }
        else if(lans!=0 && rans==0)
        {
            return lans;
        }
        else if(lans==0 && rans!=0)
        {
            return rans;
        }
        else
        {
            return 0;
        }
    }
};
