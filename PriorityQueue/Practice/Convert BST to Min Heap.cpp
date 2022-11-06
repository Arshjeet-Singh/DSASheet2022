#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/
void store(BinaryTreeNode* root,vector<int> &v)
{
    if(root==0)
    {
        return;
    }
    store(root->left,v);
    v.push_back(root->data);
    store(root->right,v);
}
void convert(BinaryTreeNode* root,vector<int> &v,int &ind)
{
    if(root==0)
    {
        return;
    }
    root->data=v[ind++];
    convert(root->left,v,ind);
    convert(root->right,v,ind);
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
    vector<int> v;
    store(root,v);
    int ind=0;
    convert(root,v,ind);
    return root;
	// Write your code here.
}
