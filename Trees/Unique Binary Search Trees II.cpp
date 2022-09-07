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
    vector<TreeNode *>helper(int l,int r)
    {
        vector<TreeNode *> ans;
        if(l>r)
        {
            ans.push_back(0);
            return ans;
        }
        else if(l==r)
        {
            ans.push_back(new TreeNode(l));
            return ans;
        }
        else
        {
            for(int i=l;i<=r;i++)
            {
                auto left=helper(l,i-1);
                auto right=helper(i+1,r);
                for(auto itr1:left)
                {
                    for(auto itr2:right)
                    {
                        TreeNode *root=new TreeNode(i);
                        root->left=itr1;
                        root->right=itr2;
                        ans.push_back(root);
                    }
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
     return helper(1,n);   
    }
};
