class Solution {
public:
    int help(int i,int j,int m,int n)
    {
        if(i>=m || j>=n)
        {
            return 0;
        }
        if(i==m-1 && j==n-1)
        {
            return 1;
        }
        int a=help(i+1,j,m,n);
        int b=help(i,j+1,m,n);
        return a+b;
    }
    int help1(int i,int j,int m,int n,vector<vector<int>> &dp)
    {
        if(i>=m || j>=n)
        {
            return 0;
        }
        if(i==m-1 && j==n-1)
        {
            return dp[i][j]=1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int a=help1(i+1,j,m,n,dp);
        int b=help1(i,j+1,m,n,dp);
        return dp[i][j]=a+b;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        // return help(0,0,m,n);
        return help1(0,0,m,n,dp);
    }
};
