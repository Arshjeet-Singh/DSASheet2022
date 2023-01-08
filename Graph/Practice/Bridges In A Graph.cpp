#include<bits/stdc++.h>
void dfs(int node,vector<int> &dis,vector<int> &low,int timer,int parent,unordered_map<int,bool> &vis,unordered_map<int,list<int>> &adj,vector<vector<int>> &ans)
{
    vis[node]=true;
    low[node]=dis[node]=timer++;
    for(auto nbr:adj[node])
    {
        if(nbr==parent)
        {
            continue;
        }
        if(!vis[nbr])
        {
            dfs(nbr,dis,low,timer,node,vis,adj,ans);
            low[node]=min(low[node],low[nbr]);
            
            //check edge ids bridge
            if(low[nbr]>dis[node])
            {
                vector<int> res;
                res.push_back(node);
                res.push_back(nbr);
                ans.push_back(res);
            }
        }
        else
        {
            low[node]=min(low[node],dis[nbr]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++)
    {
        int u,v;
        u=edges[i][0];
        v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int timer=0;
    int parent=-1;
    vector<int> dis(v,-1);
    vector<int> low(v,-1);
    unordered_map<int,bool> vis;
    vector<vector<int>> ans;
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            dfs(i,dis,low,timer,parent,vis,adj,ans);
        }
    }
    return ans;
    // Write your code here
}
