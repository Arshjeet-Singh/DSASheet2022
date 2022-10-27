#include <bits/stdc++.h> 
// Following is the Binary Tree node structure
/**************
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
    
};
***************/
void store(BinaryTreeNode<int>* root,vector<int> &v)
{
    if(root==0)
    {
        return;
    }
    store(root->left,v);
    v.push_back(root->data);
    store(root->right,v);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
    vector<int> v;
    store(root,v);
    int i=0,j=v.size()-1;
    while(i<j)
    {
        int sum=v[i]+v[j];
        if(sum==target)
        {
            return true;
        }
        else if(sum<target)
        {
            i++;
        }
        else 
        {
            j--;
        }
    }
    return false;
	//Write your code here
}
