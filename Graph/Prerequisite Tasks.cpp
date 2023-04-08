//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &vis,unordered_map<int,bool> &dfsvis,int node)
    {
        vis[node]=true;
        dfsvis[node]=true;
        for(auto i:adj[node])
        {
            if(!vis[i])
            {
                bool ans=dfs(adj,vis,dfsvis,i);
                if(ans)
                {
                    return true;
                }
            }
            else if(dfsvis[i])
            {
                return true;
            }
        }
        dfsvis[node]=false;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    unordered_map<int,list<int>> adj;
	    int p=prerequisites.size();
	    for(int i=0;i<p;i++)
	    {
	        int u=prerequisites[i].second;
	        int v=prerequisites[i].first;
	        adj[u].push_back(v);
	    }
	    unordered_map<int,bool> vis;
	    unordered_map<int,bool> dfsvis;
	    for(int i=0;i<N;i++)
	    {
	        if(!vis[i])
	        {
	            bool ans=dfs(adj,vis,dfsvis,i);
	            if(ans)
	            {
	                return false;
	            }
	        }
	    }
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends
