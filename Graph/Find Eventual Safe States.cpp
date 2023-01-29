class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph,unordered_map<int,bool> &vis,unordered_map<int,bool> &dfsvis,vector<bool> &check)
    {
        vis[node]=1;
        dfsvis[node]=1;
        check[node]=0;
        for(auto i:graph[node])
        {
            if(!vis[i])
            {
                bool ans=dfs(i,graph,vis,dfsvis,check);
                if(ans)
                {
                    check[node]=0;
                    return true;
                }
            }
            else if(dfsvis[i])
            {
                check[node]=0;
                return true;
            }
        }
        check[node]=1;
        dfsvis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n=graph.size();
        vector<bool> check(n,0);
        unordered_map<int,bool> vis,dfsvis;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                bool ans=dfs(i,graph,vis,dfsvis,check);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(check[i]==1)
            {
                ans.push_back(i);
            }
        }
      //not the right approach
        // for(int i=0;i<graph.size();i++)
        // {
        //     if(graph[i].size()==0)
        //     {
        //         ans.push_back(i);
        //     }   
        // }
        // for(int i=0;i<ans.size();i++)
        // {
        //     for(int k=0;k<graph.size();k++)
        //     {
        //         if(graph[k].size()==1)
        //         {
        //             for(int j=0;j<graph[k].size();j++)
        //             {
        //                 if(graph[k][j]==ans[i])
        //                 {
        //                     ans.push_back(k);
        //                 }
        //             }
        //         }
        //     }
        // }
        // sort(ans.begin(),ans.end());
        return ans;
    }
};
