//Using both bfs and dfs
#include<bits/stdc++.h>
bool bfs(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &vis,int node)
{
    unordered_map<int,int> p;
    p[node]=-1;
    vis[node]=1;
    queue<int> q;
    q.push(node);
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(auto i:adj[t])
        {
            if(vis[i] && p[t]!=i)
            {
                return true;
            }
            else if(!vis[i])
            {
                vis[i]=1;
                p[i]=t;
                q.push(i);
            }
        }
    }
    return false;
}
bool dfs(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &vis,int node,int p)
{
    vis[node]=true;
    for(auto i:adj[node])
    {
        if(!vis[i])
        {
            bool ans=dfs(adj,vis,i,node);
            if(ans)
            {
                return true;
            }
        }
        else if(p!=i)
        {
            return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int>> adj;
    for(int i=0;i<m;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool> vis;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
//             bool ans=bfs(adj,vis,i);
            bool ans=dfs(adj,vis,i,-1);
            if(ans)
            {
                return "Yes";
            }
        }
    }
    return "No";
    // Write your code here.
}
