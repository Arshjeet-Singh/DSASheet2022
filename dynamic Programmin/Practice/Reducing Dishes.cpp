class Solution {
public:
int solvem(vector<int>& s,int i,int t,vector<vector<int>> &dp)
{
    int n=s.size();
    if(i>=n)
    {
        return 0;
    }
    if(dp[i][t]!=-1)
    {
        return dp[i][t];
    }
    //exclude
    int ex=solvem(s,i+1,t,dp);
    int in=s[i]*t+solvem(s,i+1,t+1,dp);
    return dp[i][t]=max(in,ex);
}
int solvet(vector<int>& s)
{
    int n=s.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int t=i;t>=0;t--)
        {
            int ex=dp[i+1][t];
            int in=s[i]*(t+1)+dp[i+1][t+1];
            dp[i][t]=max(in,ex);
        }
    }
    return dp[0][0];
}
int solvet2(vector<int>& s)
{
    int n=s.size();
    // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    vector<int> next(n+1,0);
    vector<int> curr(n+1,0);
    for(int i=n-1;i>=0;i--)
    {
        for(int t=i;t>=0;t--)
        {
            int ex=next[t];
            int in=s[i]*(t+1)+next[t+1];
            curr[t]=max(in,ex);
        }
        next=curr;
    }
    return next[0];
}
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return solvem(satisfaction,0,1,dp);
        return solvet(satisfaction);
    }
};
