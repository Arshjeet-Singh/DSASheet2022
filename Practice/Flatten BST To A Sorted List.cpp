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
void store(TreeNode<int>* root,vector<int> &v)
{
    if(root==0)
    {
        return;
    }
    store(root->left,v);
    v.push_back(root->data);
    store(root->right,v);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    if(root==0)
    {
        return 0;
    }
    vector<int> v;
    store(root,v);
    TreeNode<int> *t=new TreeNode<int>(v[0]);
    t->left=0;
    TreeNode<int> *temp=t;
    for(int i=1;i<v.size();i++)
    {
        TreeNode<int> *temp1=new TreeNode<int>(v[i]);
        temp1->left=0;
        temp->right=temp1;
        temp=temp1;
    }
    temp->left=0;
    temp->right=0;
    return t;
//     temp->left=0;
//     temp->right=root;
//     root->left=0;
//     root->right=flatten(root->left);
//     return root;
    // Write your code here
}
