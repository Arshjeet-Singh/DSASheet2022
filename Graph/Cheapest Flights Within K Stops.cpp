class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,list<pair<int,int>>> adj;
        int num=flights.size();
        for(int i=0;i<num;i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            adj[u].push_back({v,w});
        }
        vector<int> dis(n,INT_MAX);
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        dis[src]=0;
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int stop=it.first;
            int dist=it.second.second;
            int node=it.second.first;
            if(stop>k)
            {
                continue;
            }
            for(auto itr:adj[node])
            {
                int adjnode=itr.first;
                int wt=itr.second;
                if(wt+dist<dis[adjnode] && stop<=k)
                {
                    cout<<adjnode<<endl;
                    dis[adjnode]=wt+dist;
                    q.push({stop+1,{adjnode,wt+dist}});
                }
            }
        }
        if(dis[dst]==INT_MAX)
        {
            return -1;
        }
        return dis[dst];
    }
};
