class Solution {
public:
int help(int i,int j,int m,int n,vector<vector<int>>& grid,vector<vector<int>> &dp)
{
    if(i>=m || j>=n)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(i==m-1 && j==n-1)
    {
        // cout<<i<<j<<endl;
        return dp[i][j]=grid[i][j];
    }
    if(i==m-1 && j!=n-1)
    {
        // cout<<i<<j<<endl;
        return dp[i][j]=grid[i][j]+help(i,j+1,m,n,grid,dp);
    }
    if(i!=m-1 && j==n-1)
    {
        // cout<<i<<j<<endl;
        return dp[i][j]=grid[i][j]+help(i+1,j,m,n,grid,dp);
    }
    if(i!=m-1 && j!=n-1)
    {
        // cout<<i<<j<<endl;
        return dp[i][j]=grid[i][j]+min(help(i,j+1,m,n,grid,dp),help(i+1,j,m,n,grid,dp));
    }
    // cout<<"a"<<i<<j<<grid[i][j]<<endl;
    // int a=grid[i][j]+help(i+1,j,m,n,grid);
    // cout<<a<<endl;
    // cout<<"b"<<i<<j<<grid[i][j]<<endl;
    // int b=grid[i][j]+help(i,j+1,m,n,grid);
    // cout<<b<<endl;
    // int a,b;
    // a=help(i+1,j,m,n,grid);
    // b=help(i,j+1,m,n,grid);
    // return min(a,b);
    return 0;
}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return help(0,0,m,n,grid,dp);
    }
};
