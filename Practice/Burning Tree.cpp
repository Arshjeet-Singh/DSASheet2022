//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  Node *createmap(Node *root,map<Node*,Node*> &mp,int target)
  {
      queue<Node *> q;
      Node *res=0;
      q.push(root);
      mp[root]=0;
      while(!q.empty())
      {
          Node *temp=q.front();
          q.pop();
          if(temp->data==target)
          {
              res=temp;
          }
          if(temp->left)
          {
              q.push(temp->left);
              mp[temp->left]=temp;
          }
          if(temp->right)
          {
              q.push(temp->right);
              mp[temp->right]=temp;
          }
      }
      return res;
  }
  int burn(Node *targetnode,map<Node*,Node*> &mp)
  {
      map<Node*,bool>vis;
      queue<Node*> q;
      q.push(targetnode);
      vis[targetnode]=true;
      int ans=0;
      while(!q.empty())
      {
          int si=q.size();
          int f=0;
          for(int i=0;i<si;i++)
          {
              Node *temp=q.front();
              q.pop();
              if(temp->left && !vis[temp->left])
              {
                  f=1;
                  q.push(temp->left);
                  vis[temp->left]=true;
              }
              if(temp->right && !vis[temp->right])
              {
                  f=1;
                  q.push(temp->right);
                  vis[temp->right]=true;
              }
              if(mp[temp] && !vis[mp[temp]])
              {
                  f=1;
                  q.push(mp[temp]);
                  vis[mp[temp]]=true;
              }
          }
          if(f==1)
          {
              ans++;
          }
      }
      return ans;
  }
    int minTime(Node* root, int target) 
    {
        if(root==0)
        {
            return 0;
        }
        map<Node*,Node*> mp;
        Node *targetnode=createmap(root,mp,target);
        int ans=burn(targetnode,mp);
        return ans;
        // Your code goes here
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends
