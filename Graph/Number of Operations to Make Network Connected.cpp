class Solution {
public:
void dfs(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &vis,int n)
{
    vis[n]=true;
    for(auto i:adj[n])
    {
        if(!vis[i])
        {
            dfs(adj,vis,i);
        }
    }
}
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
        {
            return -1;
        }
        unordered_map<int,list<int>> adj;
        unordered_map<int,bool> vis(n);
        for(int i=0;i<connections.size();i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(adj,vis,i);
            }
        }
        return cnt-1;
    }
};
