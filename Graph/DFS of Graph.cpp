//Code Studio Code
#include<bits/stdc++.h>
void dfs(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &vis,int n,vector<int> &comp)
{
    vis[n]=true;
    comp.push_back(n);
    for(auto i:adj[n])
    {
        if(!vis[i])
        {
            dfs(adj,vis,i,comp);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool> vis;
    vector<vector<int>> ans;
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            vector<int> comp;
            dfs(adj,vis,i,comp);
            ans.push_back(comp);
        }
    }
    return ans;
    // Write your code here
}
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  void dfs(vector<int> &ans,vector<int> &vis,vector<int> adj[],int i)
  {
      vis[i]=1;
      ans.push_back(i);
      for(auto x:adj[i])
      {
          if(!vis[x])
          {
              dfs(ans,vis,adj,x);
          }
      }
      
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(ans,vis,adj,i);
            }
        }
        return ans;
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
