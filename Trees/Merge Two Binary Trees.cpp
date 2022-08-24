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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==0 && root2==0)
        {
            return 0;
        }
        if(root1==0 && root2!=0)
        {
            return root2;
        }
        if(root2==0 && root1!=0)
        {
            return root1;
        }
        TreeNode *newr=new TreeNode(root1->val+root2->val);
        newr->left=mergeTrees(root1->left,root2->left);
        newr->right=mergeTrees(root1->right,root2->right);
        return newr;
        // queue<TreeNode*> q;
        // queue<TreeNode*> p;
        // q.push(root1);
        // p.push(root2);
        // while(!q.empty() || !p.empty())
        // {
        //     int a1=0;
        //     TreeNode *b;
        //     int b1=b->val;
        //     if(!q.empty())
        //     {
        //         TreeNode *a=q.front();
        //         a1=a->val;
        //     }
        //     TreeNode *hr=new TreeNode(a1+b1);
        // }
    }
};
