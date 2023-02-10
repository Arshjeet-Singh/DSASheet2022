class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,list<int>> adj;
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
            {
                adj[manager[i]].push_back(i);
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<i<<" ";
        //     for(auto nbr:adj[i])
        //     {
        //         cout<<nbr<<" ";
        //     }
        //     cout<<endl;
        // }
        int mt=0;
        unordered_map<int,int> mp;
        vector<bool> vis(n,0);
        queue<int> q;
        q.push(headID);
        mp[headID]=0;
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            cout<<a<<" ";
            for(auto nbr:adj[a])
            {
                cout<<nbr<<" ";
                mp[nbr]+=mp[a]+informTime[a];
                mt=max(mt,mp[nbr]);
                if(!vis[nbr])
                {
                    q.push(nbr);
                    vis[nbr]=1;
                }
                
            }
            cout<<endl;
        }
        return mt;
        // for(int i=0;i<n;i++)
        // {
        //     if(manager[i]!=-1)
        //     {
        //         if(!vis[manager[i]] &&mp[manager[i]].size()>0)
        //     {
        //        ans+=informTime[manager[i]];
        //         vis[manager[i]]=1;
        //     }
        //         // mp[manager[i]].push_back(i);
        //         // s.insert(manager[i]);
        //     }
        // }
        // for(auto a:mp)
        // {
        //     cout<<a<<endl;
        //     // ans+=informTime[a];
        // }
        // for(int i=0;i<n;i++)
        // {
        //     for(auto nbr:)
        //     if(manager[i]!=-1)
        //     {
        //         mp[manager[i]].push_back(i);
        //         s.insert(manager[i]);
        //     }
        // }
        // return ans;
    }
};
