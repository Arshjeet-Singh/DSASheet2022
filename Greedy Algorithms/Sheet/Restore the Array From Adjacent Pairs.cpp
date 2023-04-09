class Solution {
public:
void dfs(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &vis,int head,vector<int> &ans)
{
    vis[head]=1;
    ans.push_back(head);
    for(auto in:adj[head])
    {
        if(!vis[in])
        {
            dfs(adj,vis,in,ans);
        }
    }
}
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n=adjacentPairs.size();
        unordered_map<int,list<int>> adj;
        for(int i=0;i<n;i++)
        {
            int u=adjacentPairs[i][0];
            int v=adjacentPairs[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int head;
        for(auto i:adj)
        {
            if(i.second.size()==1)
            {
                head=i.first;
            }
        }
        unordered_map<int,bool> vis;
        vector<int> ans;
        dfs(adj,vis,head,ans);
        return ans;
    }
};
