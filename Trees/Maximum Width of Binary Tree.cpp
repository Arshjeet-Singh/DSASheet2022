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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==0)
        {
            return 0;
        }
        queue<pair<TreeNode *,long>>q;
        q.push({root,0});
        long ans=0,last=0,first=0;
        while(!q.empty())
        {
            int si=q.size();
            int mini=q.front().second;
            for(int i=0;i<si;i++)
            {
                TreeNode *temp=q.front().first;
                long cind=q.front().second-mini;
                q.pop();
                if(i==0)
                {
                    first=cind;
                }
                if(i==si-1)
                {
                    last=cind;
                }
                if(temp->left)
                {
                    q.push({temp->left,2*cind+1});
                }
                if(temp->right)
                {
                    q.push({temp->right,2*cind+2});
                }
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};
