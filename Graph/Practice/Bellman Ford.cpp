#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dis(n+1,1e9);
    dis[src]=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int u=edges[j][0];
            int v=edges[j][1];
            int w=edges[j][2];
            if(dis[u]!=1e9 && ((dis[u]+w)<dis[v]))
            {
                dis[v]=dis[u]+w;
            }
        }
    }
    return dis[dest];
   //no negative cycle in iven problem
    //check for -ve cycle
//     bool f=0;
//     for(int j=0;j<m;j++)
//         {
//             int u=edges[j][0];
//             int v=edges[j][1];
//             int w=edges[j][2];
//             if(dis[u]!=INT_MAX && (dis[u])+w<dis[v])
//             {
//                 dis[v]=dis[u]+w;
//                 f=1;
//             }
//     }
//     if(f==0)
//     {
//         return dis[dest];    
//     }
//     return -1;
    
    // Write your code here.
}
