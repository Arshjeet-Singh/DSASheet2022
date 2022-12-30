#include <bits/stdc++.h> 
void dfs(unordered_map<int,list<int>> &adj,int node,vector<bool> &vis,stack<int> &s)
{
    vis[node]=1;
    for(auto i:adj[node])
    {
        if(!vis[i])
        {
            dfs(adj,i,vis,s);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++)
    {
        int u=edges[i][0],v=edges[i][1];
        adj[u].push_back(v);
    }
    vector<bool> vis(v);
    stack<int> s;
    vector<int> ans;
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            dfs(adj,i,vis,s);
        }
    }
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
    // Write your code here
}
