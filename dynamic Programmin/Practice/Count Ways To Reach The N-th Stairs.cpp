#include <bits/stdc++.h> 
# define mod 1000000007
int countDistinctWays(int nStairs) {
    if(nStairs==0 )
    {
        return 1;
    }
    if(nStairs<0)
    {
        return 0;
    }
    vector<int> dp(nStairs+1,-1);
    if(dp[nStairs]!=-1)
    {
        return dp[nStairs];
    }
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=nStairs;i++)
    {
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    }
//     dp[nStairs]=countDistinctWays(nStairs-1)+countDistinctWays(nStairs-2);
    return dp[nStairs]%mod;
    //  Write your code here.
}
