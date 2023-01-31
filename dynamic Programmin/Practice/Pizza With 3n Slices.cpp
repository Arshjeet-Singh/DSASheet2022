class Solution {
public:
int solve(int i,int end,vector<int>& slices,int n)
{
    if(i>end || n==0)
    {
        return 0;
    }
    int in=slices[i]+solve(i+2,end,slices,n-1);
    int ex=solve(i+1,end,slices,n);
    return max(in,ex);
}
int solvem(int i,int end,vector<int>& slices,int n,vector<vector<int>> &dp)
{
    if(i>end || n==0)
    {
        return 0;
    }
    if(dp[i][n]!=-1)
    {
        return dp[i][n];
    }
    int in=slices[i]+solvem(i+2,end,slices,n-1,dp);
    int ex=solvem(i+1,end,slices,n,dp);
    return dp[i][n]=max(in,ex);
}
int solvet(vector<int>& slices)
{
    int k=slices.size();
    vector<vector<int>> dp(k+2,vector<int>(k,0));
    vector<vector<int>> dp1(k+2,vector<int>(k,0));
    for(int i=k-2;i>=0;i--)
    {
        for(int j=1;j<=k/3;j++)
        {
            int in=slices[i]+dp[i+2][j-1];
            int ex=dp[i+1][j];
            dp[i][j]=max(in,ex);
        }
    }
    for(int i=k-1;i>=1;i--)
    {
        for(int j=1;j<=k/3;j++)
        {
            int in=slices[i]+dp1[i+2][j-1];
            int ex=dp1[i+1][j];
            dp1[i][j]=max(in,ex);
        }
    }
    return max(dp[0][k/3],dp1[1][k/3]);
}
int so(vector<int>& slices)
{
    int k=slices.size();
    // vector<vector<int>> dp(k+2,vector<int>(k,0));
    // vector<vector<int>> dp1(k+2,vector<int>(k,0));
    vector<int> prev(k+2,0);
    vector<int> curr(k+2,0);
    vector<int> next(k+2,0);
    vector<int> prev1(k+2,0);
    vector<int> curr1(k+2,0);
    vector<int> next1(k+2,0);
    for(int i=k-2;i>=0;i--)
    {
        for(int j=1;j<=k/3;j++)
        {
            int in=slices[i]+next[j-1];
            int ex=curr[j];
            prev[j]=max(in,ex);
        }
        next=curr;
        curr=prev;
    }
    for(int i=k-1;i>=1;i--)
    {
        for(int j=1;j<=k/3;j++)
        {
            int in=slices[i]+next1[j-1];
            int ex=curr1[j];
            prev1[j]=max(in,ex);
        }
        next1=curr1;
        curr1=prev1;
    }
    return max(curr[k/3],curr1[k/3]);
}
    int maxSizeSlices(vector<int>& slices) {
        // int k=slices.size();
        // vector<vector<int>> dp(k,vector<int>(k,-1));
        // vector<vector<int>> dp1(k,vector<int>(k,-1));
        // int c1=solvem(0,k-2,slices,k/3,dp);
        // int c2=solvem(1,k-1,slices,k/3,dp1);
        // return max(c1,c2);
        return so(slices);
    }
};
