#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<edges;i++)
    {
        int u=vec[i][0],v=vec[i][1],w=vec[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<int> dis(vertices,INT_MAX);
    set<pair<int,int>> s;
    s.insert({0,source});
    dis[source]=0;
    while(!s.empty())
    {
        auto top=*(s.begin());
        int ndis=top.first;
        int node=top.second;
        s.erase(s.begin());
        for(auto n:adj[node])
        {
            if(n.second+ndis<dis[n.first])
            {
                auto tofind=s.find({dis[n.first],n.first});
                if(tofind!=s.end())
                {
                    s.erase({n.second+ndis,n.first});
                }
                dis[n.first]=n.second+ndis;
                s.insert({n.second+ndis,n.first});
            }
        }
    }
    return dis;
    // Write your code here.
}
