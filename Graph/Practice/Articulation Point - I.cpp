//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(int node,int parent,vector<bool> &a,vector<int> &low,vector<int> &dis,vector<int> &p,unordered_map<int,bool> &vis,int timer,vector<int> adj[])
  {
      vis[node]=true;
      low[node]=dis[node]=timer++;
      int child=0;
      for(auto nbr:adj[node])
      {
          if(nbr==parent)
          {
              continue;
          }
          if(!vis[nbr])
          {
              dfs(nbr,node,a,low,dis,p,vis,timer,adj);
              low[node]=min(low[node],low[nbr]);
              if(low[nbr]>=dis[node] && parent!=-1)
              {
                  a[node]=1;
              }
              child++;
          }
          else
          {
              low[node]=min(low[node],dis[nbr]);
          }
      }
      if(parent==-1 && child>1)
        {
            a[node]=1;
        }  
  }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<bool> a(V,0);
        vector<int> low(V,-1);
        vector<int> dis(V,-1);
        vector<int> p(V,-1);
        unordered_map<int,bool> vis;
        int timer=0;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,-1,a,low,dis,p,vis,timer,adj);
            }
        }
        vector<int>ans;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=0)
            {
                ans.push_back(i);
            }
        }
        if(ans.size()==0)
        {
            ans.push_back(-1);
        }
        return ans;
        // Code here
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
