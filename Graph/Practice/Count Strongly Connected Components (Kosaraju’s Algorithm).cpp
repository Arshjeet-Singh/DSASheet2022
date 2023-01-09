#include<bits/stdc++.h>
void dfs(int node,unordered_map<int,bool> &vis,unordered_map<int,list<int>> &adj,stack<int> &st)
{
    vis[node]=true;
    for(auto nbr:adj[node])
    {
        if(!vis[nbr])
        {
            dfs(nbr,vis,adj,st);
        }
    }
    st.push(node);
}
void ndfs(int node,unordered_map<int,bool> &vis,unordered_map<int,list<int>> &adj)
{
    vis[node]=true;
    for(auto nbr:adj[node])
    {
        if(!vis[nbr])
        {
            ndfs(nbr,vis,adj);
        }
    }
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
//         adj[v].push_back(u);
    }
    unordered_map<int,bool> vis;
    stack<int> st;
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            dfs(i,vis,adj,st);
        }
    }
    unordered_map<int,list<int>> rev;
    for(int i=0;i<v;i++)
    {
        vis[i]=0;
        for(auto nbr:adj[i])
        {
            rev[nbr].push_back(i);
        }
    }
    int cnt=0;
    unordered_map<int,bool>rvis;
    while(!st.empty())
    {
        int t=st.top();
        st.pop();
        if(!rvis[t])
        {
              cnt++;
            ndfs(t,rvis,rev);    
        }
    }
    return cnt;
	// Write your code here.
}
