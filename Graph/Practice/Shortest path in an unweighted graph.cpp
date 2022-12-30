#include<bits/stdc++.h>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i].first,v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool> vis;
    unordered_map<int,int> p;
    int src=s;
    vis[src]=1;
    p[src]=-1;
    queue<int> q;
    q.push(src);
    vector<int> ans;
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        for(auto i:adj[f])
        {
            if(!vis[i])
            {
                q.push(i);
                vis[i]=1;
                p[i]=f;
            }
        }
    }
    int des=t;
    ans.push_back(des);
    while(des!=src)
    {
        des=p[des];
        ans.push_back(des);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
