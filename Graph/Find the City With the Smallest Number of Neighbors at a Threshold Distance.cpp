class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
    for(int i=0;i<edges.size();i++)
    {
        dis[edges[i][0]][edges[i][1]]=edges[i][2];
        dis[edges[i][1]][edges[i][0]]=edges[i][2];
    }
    for(int i=0;i<n;i++)
    {
        dis[i][i]=0;
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dis[i][k]==INT_MAX || dis[k][j]==INT_MAX)
                {
                    continue;
                }
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    int city=-1;
    int mincnt=n;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        cnt=0;
        for(int j=0;j<n;j++)
        {
            if(dis[i][j]<=distanceThreshold)
            {
                cnt++;
            }
        }
        if(cnt<=mincnt)
        {
            mincnt=cnt;
            city=i;
        }
    }
    return city;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
        // unordered_map<int,list<pair<int,int>>> adj;
    //     int ansnode;
    //     int mincnt=INT_MAX;
    //     for(int i=0;i<n;i++)
    //     {
    //         int u=edges[i][0],v=edges[i][1],w=edges[i][2];
    //         adj[u].push_back({v,w});
    //         adj[v].push_back({u,w});
    //     }
    //     vector<int> dis(n,INT_MAX);
    //     set<pair<int,int>> s;
    //     for(int i=0;i<n;i++)
    //     {
    //         mincnt=INT_MAX;
    //         int source=i;
    //         s.insert({0,source});
    //         dis[source]=0;
    //         while(!s.empty())
    //         {
    //             auto top=*(s.begin());
    //             int ndis=top.first;
    //             int node=top.second;
    //             s.erase(s.begin());
    //             for(auto n:adj[node])
    //             {
    //                 if(n.second+ndis<dis[n.first])
    //                 {
    //                     auto tofind=s.find({dis[n.first],n.first});
    //                     if(tofind!=s.end())
    //                     {
    //                         s.erase({n.second+ndis,n.first});
    //                     }
    //                     dis[n.first]=n.second+ndis;
    //                     s.insert({n.second+ndis,n.first});
    //                 }
    //             }
    //         }
    //         int cnt=0;
    //         for(int j=0;j<n;j++)
    //         {
    //             cout<<dis[j]<<" ";
    //             if(dis[j]<=distanceThreshold && dis[j]!=0)
    //             {
    //                 cnt++;
    //             }
    //         }
    //         cout<<cnt<<endl;
    //         if(cnt<=mincnt)
    //         {
    //             mincnt=cnt;
    //             ansnode=i;
    //         }
    //         for(int j=0;j<n;j++)
    //         {
    //             dis[j]=INT_MAX;
    //         }
    //         s.clear();
    //     }    
    //       return ansnode;  
    }
  
};
