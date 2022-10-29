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
    TreeNode* findnode(TreeNode* root, int target)
    {
        if(root==0)
        {
            return 0;
        }
        if(root->val==target)
        {
            return root;
        }
        if(target > root->val)
        {
            return findnode(root->right,target);
        }
        else if(target<root->val)
        {
            return findnode(root->left,target);
        }
        return 0;
}
    void helper(TreeNode* root,int mini,int maxi,int &v1,int &v2)
    {
        if(root==0)
        {
            return;
        }
        if(root->val<maxi && root->val>mini)
        {
            v1=root->val;
            if(root->val<maxi)
            {
                v2=maxi;
            }
            else
            {
                v2=mini;
            }
        }
        helper(root->left,mini,root->val,v1,v2);
        helper(root->right,root->val,maxi,v1,v2);
    }
    void store(TreeNode* root,vector<int> &v)
{
    if(root==0)
    {
        return;
    }
    store(root->left,v);
    v.push_back(root->val);
    store(root->right,v);
}
    void rhelper(TreeNode* root,vector<int> &v,int &ind)
    {
        if(root==0)
        {
            return;
        }
        rhelper(root->left,v,ind);
        if(root->val!=v[ind])
        {
            root->val=v[ind];
        }
        ind++;
        rhelper(root->right,v,ind);
    }
    void recoverTree(TreeNode* root) {
        if(root==0)
        {
            return;
        }
        vector<int> v;
        store(root,v);
        sort(v.begin(),v.end());
        int ind=0;
        rhelper(root,v,ind);
//         int v1=0,v2=0;
//         helper(root,INT_MIN,INT_MAX,v1,v2);
//         TreeNode *req=findnode(root,v2),*req2=findnode(root,v1);
//         if(req!=0 && req2!=0)
//         {
//             int temp=req->val;
//         req->val=req2->val;
//         req2->val=temp;
//         }
    }
};
