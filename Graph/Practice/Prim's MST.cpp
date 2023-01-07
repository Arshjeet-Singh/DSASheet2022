#include<bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<g.size();i++)
    {
        int u,v,w;
        u=g[i].first.first;
        v=g[i].first.second;
        w=g[i].second;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> p(n+1,-1);
    vector<bool> vis(n+1,0);
    vector<int> key(n+1,INT_MAX);
    p[1]=-1;
    key[1]=0;
    for(int i=1;i<n+1;i++)
    {
        int u=INT_MAX;
        int node;
        for(int v=1;v<n+1;v++)
        {
            if(!vis[v] && key[v]<u)
            {
                u=key[v];
                node=v;
            }
        }
         vis[node]=1;
        for(auto ne:adj[node])
        {
            if(!vis[ne.first] && ne.second<key[ne.first])
            {
                p[ne.first]=node;
                key[ne.first]=ne.second;
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2;i<n+1;i++)
    {
        ans.push_back({{p[i],i},key[i]});
    }
       return ans;
    // Write your code here.
}
