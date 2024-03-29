//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool bipartite(int src, vector<int>adj[],vector<int> &color)
{
    queue<int> q;
    q.push(src);
    color[src]=1;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(auto it:adj[t])
        {
            if(color[it]==-1)
            {
                q.push(it);
                color[it]=1-color[t];
            }
            else
            {
                if(color[it]==color[t])
                {
                    return false;
                }
            }
        }    
    }
    
    return true;
    
}
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V,-1);
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	            if(!bipartite(i,adj,color))
	            {
	                return false;
	            }
	        }
	    }
	    return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends
