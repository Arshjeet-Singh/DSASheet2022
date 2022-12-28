#include<bits/stdc++.h>
bool dfs(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &vis,unordered_map<int,bool> &dfsvis,int node)
{
    vis[node]=true;
    dfsvis[node]=true;
    for(auto i:adj[node])
    {
        if(!vis[i])
        {
            bool ans=dfs(adj,vis,dfsvis,i);
            if(ans)
            {
                return true;
            }
        }
        else if(dfsvis[i])
        {
            return true;
        }
    }
    dfsvis[node]=false;
    return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i].first,v=edges[i].second;
        adj[u].push_back(v);
    }
    unordered_map<int,bool> vis;
    unordered_map<int,bool> dfsvis;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            bool ans=dfs(adj,vis,dfsvis,i);
            if(ans)
            {
                return 1;
            }
        }
    }
    return 0;
  // Write your code here.
}
