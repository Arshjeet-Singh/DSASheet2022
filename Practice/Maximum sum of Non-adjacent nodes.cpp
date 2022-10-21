//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
//User function Template for C++

//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
   /* void storelvlsum(Node *root,vector<int> &p)
    {
        if(root==0)
        {
            return;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            
            int si=q.size(),sum=0;
            for(int i=0;i<si;i++)
            {
                Node *temp=q.front();
                q.pop();
                sum+=temp->data;  
                if(temp->left)
                {
                    q.push(temp->left);    
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
             p.push_back(sum);
        }
    }*/
    pair<int,int> help(Node *root)
    {
        if(root==0)
        {
            pair<int,int> p=make_pair(0,0);
            return p; 
        }
        pair<int,int> la=help(root->left);
        pair<int,int> ra=help(root->right);
        pair<int,int> ans;
        ans.first=root->data+la.second+ra.second;
        ans.second=max(la.second,la.first)+max(ra.first,ra.second);
        return ans;
        
    }
    int getMaxSum(Node *root) 
    {
        pair<int,int> p=help(root);
        return max(p.first,p.second);
        // vector<int> p;
        // storelvlsum(root,p);
        // int esum=0,osum=0;
        // for(int i=0;i<p.size();i++)
        // {
        //     if(i%2==0 && i<p.size())
        //     {
        //         esum+=p[i];    
        //     }
        //     else if(i%2!=0 && i<p.size())
        //     {
        //         osum+=p[i];
        //     }
        // }
        // return max(osum,esum);
        // Add your code here
    }
};

//{ Driver Code Starts.

// Driver code 
int main()
{
  int t;
  scanf("%d ",&t);
  while (t--)
  {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		Solution ob;
        cout<<ob.getMaxSum(root)<<endl;
  }
  return 0;
}
// } Driver Code Ends
