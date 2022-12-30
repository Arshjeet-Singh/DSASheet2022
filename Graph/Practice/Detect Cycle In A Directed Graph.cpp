#include<bits/stdc++.h>
/*bool dfs(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &vis,unordered_map<int,bool> &dfsvis,int node)
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
}*/
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
     unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i].first-1,v=edges[i].second-1;
        adj[u].push_back(v);
    }
    //Using Kahn's BFS
    vector<int> in(n);
    for(auto i:adj)
    {
        for(auto j:i.second)
        {
            in[j]++;
        }
    }
    queue<int> q;
    vector<int> ans;
    for(int i=0;i<in.size();i++)
    {
        if(in[i]==0)
        {
            q.push(i);
        }
    }
    int cnt=0;
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        ans.push_back(f);
        cnt++;
        for(auto i:adj[f])
        {
             in[i]--;
            if(in[i]==0)
            {
                q.push(i);
            }    
        }
    }
    if(cnt==n)
    {
        return false;
    }
    else
    {
        return true;
    }
//     return !(cnt==n);
   /* unordered_map<int,list<int>> adj;
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
    return 0;*/
  // Write your code here.
}
