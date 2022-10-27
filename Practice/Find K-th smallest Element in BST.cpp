#include <bits/stdc++.h> 
/*************************************************************
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int helper(BinaryTreeNode<int>* root, int k,int &count)
{
    if(root==0)
    {
        return -1;
    }
     int left=helper(root->left,k,count);
   if(left!=-1)
   {
       return left;
   }
    count++;
      if(count==k)
    {
        return root->data;
      }
    return helper(root->right,k,count);
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int count=0;
    if(root==0)
    {
        return -1;
    }
    return helper(root,k,count);
//     return count;
    // Write your code here.
}
