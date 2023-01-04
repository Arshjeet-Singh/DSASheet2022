//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void dfs(stack<int> &s,unordered_map<int,list<pair<int,int>>> &adj,int node,unordered_map<int,bool> &vis)
  {
      vis[node]=1;
      for(auto i:adj[node])
      {
          if(!vis[i.first])
          {
              dfs(s,adj,i.first,vis);
          }
      }
      s.push(node);
  }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         vector<int> dis(N,INT_MAX);
         unordered_map<int,list<pair<int,int>>> adj;
         for(int i=0;i<M;i++)
         {
             int u=edges[i][0],v=edges[i][1],w=edges[i][2];
             pair<int,int> p={v,w};
             adj[u].push_back(p);
         }
         unordered_map<int,bool> vis;
         stack<int> s;
         for(int i=0;i<N;i++)
         {
             if(!vis[i])
             {
                 dfs(s,adj,i,vis);
             }
         }
         int src=0;
         dis[0]=0;
         while(!s.empty())
         {
             int n=s.top();
             s.pop();
                 if(dis[n]!=INT_MAX)
                 {
                      for(auto i:adj[n])
                      {
                          if(i.second+dis[n]<dis[i.first])
                          {
                              dis[i.first]=dis[n]+i.second;
                          }
                      }
                 }
         }
         for(int i=0;i<dis.size();i++)
         {
             if(dis[i]==INT_MAX)
             {
                 dis[i]=-1;
             }
         }
         return dis;
        // code here
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
