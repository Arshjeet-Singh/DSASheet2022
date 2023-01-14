#include <bits/stdc++.h> 
int solve(vector<int> &num, int x)
{
    if(x==0)
    {
        return 0;
    }
    if(x<0)
    {
        return INT_MAX;
    }
    int mini=INT_MAX;
    for(int i=0;i<num.size();i++)
    {
        int ans=solve(num,x-num[i]);
        if(ans!=INT_MAX)
        {
            mini=min(mini,1+ans);    
        }
    }
    return mini;
}
int solvem(vector<int> &num, int x,vector<int> &dp)
{
    if(x==0)
    {
        dp[0]=0;
        return 0;
    }
    if(x<0)
    {
        return INT_MAX;
    }
    int mini=INT_MAX;
    if(dp[x]!=-1)
    {
        return dp[x];
    }
    for(int i=0;i<num.size();i++)
    {
        int ans=solvem(num,x-num[i],dp);
        if(ans!=INT_MAX)
        {
            mini=min(mini,1+ans);    
        }
    }
    dp[x]=mini;
    return dp[x];
}
int solvetab(vector<int> &num, int x)
{
    vector<int>dp(x+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<num.size();j++)
        {
//             int ans=;
            if(i-num[j]>=0 && dp[i-num[j]]!=INT_MAX)
            {
                dp[i]=min(dp[i],1+dp[i-num[j]]);    
            }
        }
    }
    if(dp[x]==INT_MAX)
    {
        return -1;
    }
    return dp[x];
}
int minimumElements(vector<int> &num, int x)
{
//     int ans=solve(num,x);
//     if(ans==INT_MAX)
//     {
//         return -1;
//     }
//     return ans;
    //Memoisation
//     vector<int> dp(x+1,-1);
//     int ans=solvem(num,x,dp);
//     if(ans==INT_MAX)
//     {
//         return -1;
//     }
//     return ans;
    //tabulation
    return solvetab(num,x);
    // Write your code here.
}
