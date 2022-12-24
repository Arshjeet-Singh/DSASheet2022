//{ Driver Code Starts
//GFG wala code
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // int n=adj.size();
        queue<int> q;
        q.push(0);
        // int i=0;
        vector<int> v;
        vector<int> visited(V,0);
        visited[0]=1;
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            v.push_back(a);
            for(auto i:adj[a])
            {
                if(!visited[i])
                {
                    q.push(i);
                    visited[i]=1;
                }
            }
        }
        return v;
         // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
////////////////////
// Code studio wala code
#include <bits/stdc++.h> 
void bfs(unordered_map<int,set<int>> &adj,unordered_map<int,bool> &vis,vector<int> &ans,int node)
{
    queue<int> q;
    q.push(node);
    vis[node]=1;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        ans.push_back(temp);
        for(auto i:adj[temp])
        {
            if(!vis[i])
            {
                q.push(i);
                vis[i]=1;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int,bool> vis;
    unordered_map<int,set<int>> adj;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    vector<int> ans;
    for(int i=0;i<vertex;i++)
    {
        if(!vis[i])
        {
            bfs(adj,vis,ans,i);
        }
    }
//     sort(ans.begin(),ans.end());
    return ans;
    // Write your code here
}


