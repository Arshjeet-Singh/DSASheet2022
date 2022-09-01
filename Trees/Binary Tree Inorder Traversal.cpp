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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root==0)
        {
            return v;
        }
        stack<TreeNode*> s;
        TreeNode *node=root;
        while(1)
        {
            if(node)
            {
                s.push(node);
                node=node->left;
            }
            else
            {
                if(!s.empty())
                {
                    TreeNode *a=s.top();
                    s.pop();
                    v.push_back(a->val);
                    if(a->right)
                    {
                      node=a->right;
                    }
                }
                else
                {
                    break;
                }
            }
            // TrreeNode *a=s.top();
        }
        return v;
        // v=inorderTraversal(root->left);
        // v.push_back(root->val);
        // v=inorderTraversal(root->right);
        // return v;
    }
};
