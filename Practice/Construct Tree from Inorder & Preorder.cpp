//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int findpos(int ele,int in[],int n)
    {
        for(int i=0;i<n;i++)
        {
            if(in[i]==ele)
            {
                return i;
            }
        }
        return -1;
    }
    Node *helper(int in[],int pre[],int &ind,int si,int ei,int n)
    {
        if(ind>=n || si>ei)
        {
            return 0;
        }
        int ele=pre[ind++];
        Node *root=new Node(ele);
        int pos=findpos(ele,in,n);
        root->left=helper(in,pre,ind,si,pos-1,n);
        root->right=helper(in,pre,ind,pos+1,ei,n);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int ind=0;
        return helper(in,pre,ind,0,n-1,n);
        // int si=pre[]
        // Node *root;     
        // Code here
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends
