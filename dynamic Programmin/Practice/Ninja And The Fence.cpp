#include <bits/stdc++.h> 
# define mod 1000000007
int add(int a,int b)
{
    return (a%mod+b%mod)%mod;
}
int mul(int a,int b)
{
    return (a%mod*1LL*b%mod)%mod;
}
int solve(int n, int k,vector<int> &dp)
{
    if(n==1)
    {
        return k;
    }
    if(n==2)
    {
        return add(k,mul(k,k-1));
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    dp[n]=add(mul(solve(n-2,k,dp),k-1),mul(solve(n-1,k,dp),k-1));
    return dp[n];
}
int solvetab(int n, int k)
{
    vector<int> dp(n+1,0);
    dp[1]=k;
    dp[2]=add(k,mul(k,k-1));
    for(int i=3;i<n+1;i++)
    {
        dp[i]=add(mul(dp[i-2],k-1),mul(dp[i-1],k-1));
    }
    return dp[n];
}
int sp(int n, int k)
{
//     vector<int> dp(n+1,0);
    int prev1,prev2;
    prev2=k;
    prev1=add(k,mul(k,k-1));
    for(int i=3;i<n+1;i++)
    {
        int ans;
        ans=add(mul(prev2,k-1),mul(prev1,k-1));
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
int numberOfWays(int n, int k) {
//     vector<int> dp(n+1,-1);
    return sp(n,k);
    // Write your code here.
}
