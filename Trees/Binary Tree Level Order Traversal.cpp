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
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> v;
        if(root==0)
        {
            return v;
        }
             vector<int> v1;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty())
        {
            int si=q.size();
            for(int i=0;i<si;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                v1.push_back(temp->val);
                if(temp->left)
                {
                    q.push(temp->left);
                }
                 if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            v.push_back(v1);
            v1.clear();
        }
        return v;
    }
};
