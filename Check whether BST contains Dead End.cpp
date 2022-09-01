//{ Driver Code Starts
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


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        
     cout<<isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends


/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
bool isDeadEnd(Node *root)
{
    if(root==0)
    {
        return false;
    }
    unordered_map<int,int> mp1;
    queue<Node *> q;
    unordered_map<int,int> mp2;
    q.push(root);
    while(!q.empty())
    {
        Node *a=q.front();
        q.pop();
        if(a->left==0 && a->right==0)
        {
            mp2[a->data]++;
        }
        mp1[a->data]++;
        if(a->left)
        {
            q.push(a->left);
        }
        if(a->right)
        {
            q.push(a->right);
        }
    }
    mp1[0]++;
    for(auto a:mp2)
    {
        int x=a.first;
        if(mp1[x-1]>0 && mp1[x+1]>0)
        {
            return true;
        }
    }
    return false;
    //Your code here
}
