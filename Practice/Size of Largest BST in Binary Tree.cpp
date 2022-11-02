#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
class info
{
    public:
    int maxi;
    int mini;
    int size;
    bool isbst;
};
info solve(TreeNode<int>* root,int &size)
{
    if(root==0)
    {
        return {INT_MIN,INT_MAX,0,true};
    }
    info left=solve(root->left,size);
    info right=solve(root->right,size);
    info ans;
    ans.size=left.size+right.size+1;
    ans.mini=min(left.mini,root->data);
    ans.maxi=max(right.maxi,root->data);
    if(left.isbst && right.isbst &&(root->data>left.maxi && root->data<right.mini))
    {
        ans.isbst=true;
    }
    else
    {
        ans.isbst=false;
    }
    if(ans.isbst)
    {
        size=max(size,ans.size);
    }
    return ans;
}
int largestBST(TreeNode<int>* root) 
{
    int maxsize=0;
    info temp=solve(root,maxsize);
    return maxsize;
    // Write your code here.
}
