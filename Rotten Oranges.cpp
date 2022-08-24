//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    // int bfs(vector<vector<int>>& grid,vector<vector<int>> &vis,int i,int j)
    // {
    //     int n=grid.size();
    //     int m=grid[0].size();
        
    // }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        queue<pair<pair<int,int>,int>> q; 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    vis[i][j]=2;
                    q.push({{i,j},0});
                    // bfs(grid,visited,i,j);                    
                }
            }
        }
        int dr[]={-1,0,1,0};   
        int dc[]={0,1,0,-1};
        // int ans=0
        while(!q.empty())
        {
             int r=q.front().first.first;
             int c=q.front().first.second;
             int time=q.front().second;
             ans=max(time,ans);
             q.pop();
             for(int i=0;i<4;i++)
            {
                int crow=r+dr[i];
                int ccol=c+dc[i];
                if(crow>=0 && crow<n && ccol>=0 && ccol<m && vis[crow][ccol]!=2 && grid[crow][ccol]==1)
                {
                    q.push({{crow,ccol},time+1});
                    // ans=time+1;
                    grid[crow][ccol]=2;
                    vis[crow][ccol]=1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return ans;
        // Code here
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
