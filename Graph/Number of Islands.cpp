class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        int ans;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j] && grid[i][j]=='1')
                {
                    ans++;
                    visited[i][j]=1;
                    q.push({i,j});
                }
                while(!q.empty())
                {
                    int r=q.front().first;
                    int c=q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++)
                    {
                        int cr=r+dr[k];
                        int cc=c+dc[k];
                        if(cr>=0 && cr<m && cc>=0 && cc<n && !visited[cr][cc] && grid[cr][cc]=='1')
                        {
                            visited[cr][cc]=1;
                            q.push({cr,cc});
                        }
                    }
                }
            }
        }
        return ans;
    }
};
