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
    int findele(int ele,vector<int>& postorder,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(ele==postorder[i])
            {
                return i;
            }
        }
        return -1;
    }
    map<int,int> mp;
    TreeNode *helper(vector<int>& preorder, vector<int>& postorder,int pres,int pree,int poss,int pose)
    {
        if(pres>pree)
        {
            return 0;
        }
        TreeNode *root=new TreeNode(preorder[pres]);
        if(pres==pree)
        {
            return root;
        }
        int idx=mp[preorder[pres+1]];
        int len=idx-poss+1;
        root->left=helper(preorder,postorder,pres+1,pres+len,poss,idx);
        root->right=helper(preorder,postorder,pres+len+1,pree,idx+1,pose-1);
        return root;
        // int ele=postorder[ind--];
        // TreeNode* root=new TreeNode(ele);
        // int pos=findele(ele,preorder,n);
        // root->left=helper(preorder,postorder,ind,si+1,pos-1,n);
        // root->right=helper(preorder,postorder,ind,pos+1,ei,n);
        // return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        int ind=n-1;
        for(int i=0;i<n;i++)
        {
            mp[postorder[i]]=i;
        }
        return helper(preorder,postorder,0,n-1,0,n-1);
    }
};
