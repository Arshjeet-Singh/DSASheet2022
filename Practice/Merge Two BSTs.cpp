#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/
void convdll(TreeNode<int> *root,TreeNode<int> *head)
{
    if(root==0)
    {
        return;
    }
    convdll(root->right,head);
    root->right=head;
    if(head!=0)
    {
        head->left=root;    
    }
    head=root;
    convdll(root->left,head); 
}
TreeNode<int> *merge(TreeNode<int> *root1,TreeNode<int> *root2)
{
   
    TreeNode<int> *head=0,*tail=0;
    while(root1!=0 && root2!=0)
    {
        if(root1->data<root2->data)
        {
            if(head==0)
            {
                head=tail=root1;
                root1=root1->right;
            }
            else
            {
                tail->right=root1;
                root1->left=tail;
                 tail=root1;
                root1=root1->right;
               
            }    
        }
        else
        {
            if(head==0)
            {
                head=tail=root2;
                root2=root2->right;
            }
            else
            {
                tail->right=root2;
                root2->left=tail;
                tail=root2;
                root2=root2->right;
            }
        }
    }
    while(root1!=0)
    {
        tail->right=root1;
                root1->left=tail;
         tail=root1;
                root1=root1->right;
               
    }
    while(root2!=0)
    {
        tail->right=root2;
                root2->left=tail;
          tail=root2;
                root2=root2->right;
              
    }
    return head;
}
int count(TreeNode<int> *head)
{
    TreeNode<int> * temp=head;
    int c=0;
    while(temp!=0)
    {
        c++;
        temp=temp->right;
    }
    return c;
}
TreeNode<int> * lltobst(TreeNode<int> *head,int n)
{
    if(head==0 || n<=0)
    {
        return 0;
    }
    TreeNode<int> *left=lltobst(head,n/2);
    TreeNode<int> *root=head;
    root->left=left;
    head=head->right;
    root->right=lltobst(head,n-n/2-1);
    return root;
}
void store(TreeNode<int> *root,vector<int> &v)
{
    if(root==0)
    {
        return;
    }
    store(root->left,v);
    v.push_back(root->data);
    store(root->right,v);
}
vector<int> merge(vector<int> v1,vector<int> v2)
{
    vector<int> v(v1.size()+v2.size());
    int n=v1.size();
    int m=v2.size();
    int i=0,j=0;
    int k=0;
    while(i<n && j<m)
    {
        if(v1[i]<v2[j])
        {
            v[k++]=v1[i++];
        }
        else
        {
            v[k++]=v2[j++];
        }
    }
    while(i<n)
    {
        v[k++]=v1[i++];
    }
    while(j<m)
    {
        v[k++]=v2[j++];        
    }
    return v;
}
TreeNode<int> *arrtobst(vector<int> v,int s,int e)
{
    if(s>e)
    {
        return 0;
    }
    int m=s+(e-s)/2;
    TreeNode<int> *root=new TreeNode<int>(v[m]);
    root->left=arrtobst(v,s,m-1);
    root->right=arrtobst(v,m+1,e);
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    vector<int> v1,v2;
    store(root1,v1);
    store(root2,v2);
    vector<int> v=merge(v1,v2);
    return arrtobst(v,0,v.size()-1);
    //for approach witth less time complexity was giving runtime don't know why
    //     TreeNode<int> *head1=0;
//     convdll(root1,head1);
//     head1->left=0;
//     TreeNode<int> *head2=0;
//     convdll(root2,head2);
//     head2->left=0;
//     TreeNode<int> *head=merge(head1,head2);
//     int c=count(head);
//     return lltobst(head,c);
    
    // Write your code here.
}
