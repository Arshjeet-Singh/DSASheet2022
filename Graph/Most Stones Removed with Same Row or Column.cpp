class Solution {
public:
    // int findparent(vector<int> &p,int node)
    // {
    //     if(p[node]==node)
    //     {
    //         return node;
    //     }
    //     return p[node]=findparent(p,p[node]);
    // }
    // void unionset(vector<int> &p,vector<int> &r,int u,int v)
    // {
    //     u=findparent(p,u);
    //     v=findparent(p,v);
    //     if(r[u]<r[v])
    //     {
    //         p[u]=v;
    //     }
    //     else if(r[v]>r[u])
    //     {
    //         p[v]=u;
    //     }
    //     else
    //     {
    //         p[v]=u;
    //         r[u]++;
    //     }
    // }
    // void unionbysize(vector<int> &p,vector<int> &si,int u,int v)
    // {
    //     u=findparent(p,u);
    //     v=findparent(p,v);
    //     if(u==v)
    //     {
    //         return;
    //     }
    //     if(si[u]<si[v])
    //     {
    //         p[u]=v;
    //         si[v]+=si[u];
    //     }
    //     else
    //     {
    //         p[v]=u;
    //         si[u]+=si[v];
    //     }
    // }
    void dfs(vector<int> &vis,vector<vector<int>>& stones,int i)
    {
        vis[i]=1;
        for(int j=0;j<stones.size();j++)
        {
            if(vis[j])
            {
                continue;
            }
            else if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
            {
                dfs(vis,stones,j);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
    
    int cnt=0;
    int n=stones.size();
    vector<int> vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(vis,stones,i);
            cnt++;
        }
    }
    return n-cnt;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //     int mr=0,mc=0;
    //     int n=stones.size();
    //     for(int i=0;i<n;i++)
    //     {
    //         if(stones[i][0]>mr)
    //         {
    //             mr=stones[i][0];
    //         }
    //         if(stones[i][1]>mc)
    //         {
    //             mc=stones[i][1];
    //         }
    //     }
    //    vector<int> p(mc+mr+1);
    //     // vector<int> r(mc+mr+1,0);
    //     vector<int> si(mc+mr+1,1);
    //     for(int i=0;i<mc+mr+1;i++)
    //     {
    //         p[i]=i;
    //     }
    //     unordered_map<int,int> stonenodes;
    //     int cnt=0;
    //     for(int i=0;i<n;i++)
    //     {
    //         int u=stones[i][0];
    //         int v=stones[i][1]+mr+1;
    //         unionbysize(p,si,u,v);
    //         stonenodes[u]=1;
    //         stonenodes[v]=1;
    //     }
    //     // for(auto it:stonenodes)
    //     // {
    //     //     if(findparent(p,it.first)==it.first)
    //     //     {
    //     //         cnt++;
    //     //     }
    //     // }
    //     return stones.size()-cnt;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // unordered_map<int,int> rmp;
        // unordered_map<int,int> cmp;
        // unordered_map<int,int> rmp1;
        // unordered_map<int,int> cmp1;
        // int n=stones.size();
        // // sort(stones.begin(),stones.end());
        // for(int i=0;i<n;i++)
        // {
        //     rmp[stones[i][0]]++;
        //     cmp[stones[i][1]]++;
        //     rmp1[stones[i][0]]++;
        //     cmp1[stones[i][1]]++;
        // }
        // int ans=0,ans1=0;
        // for(int i=0;i<n;i++)
        // {
        //     if(rmp[stones[i][0]]>1)
        //     {
        //         ans++;
        //         rmp[stones[i][0]]--;
        //         cmp[stones[i][1]]--;
        //     }
        //     else if(cmp[stones[i][1]]>1)
        //     {
        //         ans++;
        //         rmp[stones[i][0]]--;
        //         cmp[stones[i][1]]--;
        //     }
        //     if(cmp1[stones[i][1]]>1)
        //     {
        //         ans1++;
        //         rmp1[stones[i][0]]--;
        //         cmp1[stones[i][1]]--;
        //     }
        //     else if(rmp1[stones[i][1]]>1)
        //     {
        //         ans1++;
        //         rmp1[stones[i][0]]--;
        //         cmp1[stones[i][1]]--;
        //     }
        // }
        // return max(ans,ans1);
    }
};
