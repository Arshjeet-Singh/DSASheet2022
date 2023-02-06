class Solution {
public:
int solve(int s,int end)
{
    if(s>=end)
    {
        return 0;
    }
    int mini=INT_MAX;
    for(int i=s;i<=end;i++)
    {
        mini=min(mini,i+max(solve(s,i-1),solve(i+1,end)));
    }
    return mini;
}
int solvem(int s,int end,vector<vector<int>> &dp)
{
    if(s>=end)
    {
        return 0;
    }
    if(dp[s][end]!=-1)
    {
        return dp[s][end];
    }
    int mini=INT_MAX;
    for(int i=s;i<=end;i++)
    {
        mini=min(mini,i+max(solvem(s,i-1,dp),solvem(i+1,end,dp)));
    }
    return dp[s][end]=mini;
}
int solvet(int n)
{
    vector<vector<int>> dp(n+2,vector<int>(n+1,0));
    for(int s=n;s>=1;s--)
    {
        for(int e=s;e<=n;e++)
        {
            if(s==e)
            {
                continue;
            }
            int mini=INT_MAX;
            for(int i=s;i<=e;i++)
            {
                mini=min(mini,i+max(dp[s][i-1],dp[i+1][e]));
            }
             dp[s][e]=mini;
        }
    }
    return dp[1][n];
}
    int getMoneyAmount(int n) {
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return solvem(1,n,dp);
        return solvet(n);
    }
};
