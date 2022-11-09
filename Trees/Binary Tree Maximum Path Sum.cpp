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
    void solve(TreeNode* root,int &maxi,vector<int> &path)
    {
        // if(root==0)
        // {
        //     return;
        // }
        // path.push_back(root->val);
        // solve(root->left,maxi,path);
        // solve(root->right,maxi,path);
        // int si=path.size(),sum=0;
        // for(int i=si-1;i>=0;i--)
        // {
        //     sum+=path[i];
        //     if(sum>maxi)
        //     {
        //         maxi=sum;
        //     }
        // }
        // path.pop_back();
    }
    int solve1(TreeNode *root,int &maxi)
    {
        if(root==0)
        {
            return 0;
        }
        int left=max(0,solve1(root->left,maxi));
        int right=max(0,solve1(root->right,maxi));
        maxi=max(maxi,root->val+left+right);
        return root->val+max(right,left);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        // vector<int> path;
        // solve(root,maxi,path);
        int s=solve1(root,maxi);
        return maxi;
    }
};
