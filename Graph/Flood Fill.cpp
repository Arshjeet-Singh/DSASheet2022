class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         int m=image.size();
        int n=image[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        int ans;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int num=image[sr][sc];
        visited[sr][sc]=1;
        image[sr][sc]=color;
        q.push({sr,sc});
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int cr=r+dr[k];
                int cc=c+dc[k];
                if(cr>=0 && cr<m && cc>=0 && cc<n && !visited[cr][cc] && image[cr][cc]==num)
                {
                    visited[cr][cc]=1;
                    q.push({cr,cc});
                    image[cr][cc]=color;
                }
            }
        }
        return image;
        
    }
};
