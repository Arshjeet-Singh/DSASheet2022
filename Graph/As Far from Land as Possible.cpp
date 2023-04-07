class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    vis[i][j]=1;
                   
                    q.push({{i,j},0});
                }
                else
                {
                    vis[i][j]=0;
                }
            }
        }
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
        while(!q.empty())
        {
            int cr=q.front().first.first;
            int cc=q.front().first.second;
            int dist=q.front().second;
            q.pop();
             dis[cr][cc]=dist;
            for(int i=0;i<4;i++)
            {
                int r=cr+dr[i];
                int c=cc+dc[i];
                if(r>=0 && r<n && c>=0 && c<n && !vis[r][c])
                {
                    q.push({{r,c},dist+1});
                    vis[r][c]=1;
                }
            }
            
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                maxi=max(maxi,dis[i][j]);
                cout<<dis[i][j]<<" ";
            }
            cout<<endl;
        }
        if(maxi==0)
        {
            return -1;
        }
        return maxi;
    }
};
