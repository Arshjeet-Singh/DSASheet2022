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
    void helper(TreeNode *root,vector<int> &v)
    {
        if(root==0)
        {
            return;
        }
        
        helper(root->left,v);
        v.push_back(root->val);
        helper(root->right,v);
    }
    int getMinimumDifference(TreeNode* root) {
       vector<int> v;
        helper(root,v);
        int ans=INT_MAX;
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
        for(int i=1;i<v.size();i++)
        {
            ans=min(ans,abs(v[i]-v[i-1]));
        }
        return ans;
    }
};
