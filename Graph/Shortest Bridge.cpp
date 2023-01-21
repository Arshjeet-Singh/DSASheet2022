class Solution {
public:
    void floodfill(int x,int y,vector<vector<int>>& grid,vector<pair<int,int>> &v)
    {
        queue<pair<int,int>> q;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        q.push({x,y});
        v.push_back({x,y});
        grid[x][y]=0;
        while(!q.empty())
        {
            int i=q.front().first,j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int r=i+dr[k],c=j+dc[k];
                if(r>=0 && r<grid.size() && c>=0 && c<grid[i].size() && grid[r][c])
                {
                    q.push({r,c});
                    v.push_back({r,c});
                    grid[r][c]=0;
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        vector<pair<int,int>> x,y;
        int cnt=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j])
                {
                    cnt++;
                    if(cnt==1)
                    {
                        floodfill(i,j,grid,x);
                    }
                    else if(cnt==2)
                    {
                        floodfill(i,j,grid,y);
                    }
                }
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<x.size();i++)
        {
            for(int j=0;j<y.size();j++)
            {
                if(abs(x[i].first-y[j].first)+abs(x[i].second-y[j].second)-1<mini)
                {
                    mini=abs(x[i].first-y[j].first)+abs(x[i].second-y[j].second)-1;
                }
            }
        }
        return mini;
    }
};
