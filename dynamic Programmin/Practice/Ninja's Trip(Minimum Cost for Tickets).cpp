#include<bits/stdc++.h>
int solve(int n, vector<int> &days, vector<int> &cost,int ind)
{
    if(ind>=n)
    {
        return 0;
    }
    int op1=cost[0]+solve(n,days,cost,ind+1);
    int i;
    for(i=ind;i<n &days[i]<days[ind]+7;i++);
    int op2=cost[1]+solve(n,days,cost,i);
    for(i=ind;i<n &&days[i]<days[ind]+30;i++);
    int op3=cost[2]+solve(n,days,cost,i);
    return min(op1,min(op2,op3));
}
int solvem(int n, vector<int> &days, vector<int> &cost,int ind,vector<int> &dp)
{
    if(ind>=n)
    {
        return 0;
    }
    if(dp[ind]!=-1)
    {
        return dp[ind];
    }
    int op1=cost[0]+solvem(n,days,cost,ind+1,dp);
    int i;
    for(i=ind;i<n &&days[i]<days[ind]+7;i++);
    int op2=cost[1]+solvem(n,days,cost,i,dp);
    for(i=ind;i<n &&days[i]<days[ind]+30;i++);
    int op3=cost[2]+solvem(n,days,cost,i,dp);
    return dp[ind]=min(op1,min(op2,op3));
}
int solvet(int n, vector<int> &days, vector<int> &cost)
{
    vector<int> dp(n+1,0);
    dp[n]=0;
    for(int k=n-1;k>=0;k--)
    {
        int op1=cost[0]+dp[k+1];
    int i;
    for(i=k;i<n &&days[i]<days[k]+7;i++);
    int op2=cost[1]+dp[i];
    for(i=k;i<n &&days[i]<days[k]+30;i++);
    int op3=cost[2]+dp[i];
        dp[k]=min(op1,min(op2,op3));
    }
    return dp[0];
    
}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // vector<int> dp(n+1,-1);
    // return solvet(n,days,cost);
    int ans=0;
    queue<pair<int,int>> month;
    queue<pair<int,int>> week;
    for(auto day:days)
    {
        while(!month.empty() && month.front().first+30<=day)
        {
            month.pop();
        }
        while(!week.empty() && week.front().first+7<=day)
        {
            week.pop();
        }
        month.push({day,ans+cost[2]});
        week.push({day,ans+cost[1]});
        ans=min(ans+cost[0],min(month.front().second,week.front().second));
    }
    return ans;
    // Write your code here.
}
