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
    void getmapping(TreeNode *root,unordered_map<TreeNode *,TreeNode *> &mp)
    {
        queue<TreeNode *> q;
        q.push(root);
        // mp[root]=0;
        while(!q.empty())
        {
            TreeNode *temp=q.front();
            q.pop();
            if(temp->left)
            {
                q.push(temp->left);
                mp[temp->left]=temp;
            }
            if(temp->right)
            {
                q.push(temp->right);
                mp[temp->right]=temp;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *,TreeNode *> mp;
        queue<TreeNode *> q;
        vector<int> v;
        getmapping(root,mp);
        unordered_map<TreeNode *,bool> vis;
        q.push(target);
        vis[target]=true;
        int cnt=0;
        while(!q.empty())
        {
            int size=q.size();
            if(cnt++ == k)
            {
                break;
            }
            for(int i=0;i<size;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                if(temp->left && !vis[temp->left])
                {
                    q.push(temp->left);
                    vis[temp->left]=true;
                }
                if(temp->right && !vis[temp->right])
                {
                    q.push(temp->right);
                    vis[temp->right]=true;
                }
                if(mp[temp] && !vis[mp[temp]])
                {
                    q.push(mp[temp]);
                    vis[mp[temp]]=true;
                }
            }
        }
        while(!q.empty())
        {
            TreeNode *temp=q.front();
            q.pop();
                v.push_back(temp->val);    
        }
        return v;
    }
};
