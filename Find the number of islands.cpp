// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    private:
    bool safe(int row,int col,vector<vector<char>>& grid, vector<vector<int>>& visited)
    {
        int n=grid.size();
        int m=grid[0].size();
        return ((row>=0 && row<n) && (col>=0 && col<m) &&(!visited[row][col] && grid[row][col]=='1'));
    }
    void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& visited)
    {
        int rop[]={1,1,0,-1,-1,-1,0,1};
        int cop[]={0,-1,-1,-1,0,1,1,1};
        visited[row][col]=1;
        for(int i=0;i<8;i++)
        {
            if(safe(row+rop[i],col+cop[i],grid,visited))
            {
                dfs(row+rop[i],col+cop[i],grid,visited);
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // bool visited[n][m];
         vector<vector<int>> visited( n , vector<int> (m, 0));
        // memset(visited,0,sizeof(visited));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j]=='1')
                {
                    dfs(i,j,grid,visited);
                    count++;
                }
            }
        }
        return count;
        // Code here
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends
