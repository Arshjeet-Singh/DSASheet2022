# define mod 1000000007
#include<bits/stdc++.h>
long long int solve(int n)
{
    if(n==1)
    {
        return 0;
    }
    if(n==2)
    {
        return 1;
    }
    return (n-1)%mod*(solve(n-1)%mod +solve(n-2)%mod);
}
long long int solvem(int n,vector<long long int> &dp)
{
    if(n==1)
    {
        return 0;
    }
    if(n==2)
    {
        return 1;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    return dp[n]=((n-1)%mod*(solvem(n-1,dp)%mod +solvem(n-2,dp)%mod))%mod;
}
long long int solvet(int n)
{
    vector<long long int> dp(n+1,0);
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;i++)
    {
        dp[i]=((i-1)%mod*((dp[i-1])%mod+(dp[i-2])%mod))%mod;
    }
    return dp[n];
}
long long int space(int n)
{
    //vector<long long int> dp(n+1,0);
    long long int prev2,prev1;
    prev2=0;
    prev1=1;
    for(int i=3;i<=n;i++)
    {
        long long int ans;
        ans=((i-1)%mod*((prev1)%mod+(prev2)%mod))%mod;
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
long long int countDerangements(int n) {
    long long int ans;
    //ans=solve(n);
    //vector<long long int> dp(n+1,-1);
    return space(n);
    //return ans;
    // Write your code here.
}
