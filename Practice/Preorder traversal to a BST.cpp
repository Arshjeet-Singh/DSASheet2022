#include <bits/stdc++.h> 
/*
    Following is the class structure of BinaryTreeNode class for referance:

    class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*/
BinaryTreeNode<int>* help(vector<int> &preorder,int mini,int maxi,int &i)
{
    if(i>=preorder.size())
    {
        return 0;
    }
    if(preorder[i]<mini || preorder[i]>maxi)
    {
        return 0;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(preorder[i++]);
    root->left=help(preorder,mini,root->data,i);
    root->right=help(preorder,root->data,maxi,i);
    return root;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int ind=0;
    return help(preorder,INT_MIN,INT_MAX,ind);
    // Write your code here.
}
