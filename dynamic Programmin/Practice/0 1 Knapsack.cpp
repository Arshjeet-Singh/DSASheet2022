#include <bits/stdc++.h>
int solve(vector<int> &weight,vector<int> &value,int i,int cap,vector<vector<int>> &dp)
{
    if(i==0)
    {
        if(weight[i]<=cap)
        {
             return value[0];
        }
        else
        {
        	 return 0;    
        }
    }
    if(dp[i][cap]!=-1)
    {
        return dp[i][cap];
    }
    int incl=0,excl;
    if(weight[i]<=cap)
    {
     	incl=value[i]+solve(weight,value,i-1,cap-weight[i],dp);   
    }
    excl=solve(weight,value,i-1,cap,dp);
    int ans=max(incl,excl);
    return dp[i][cap]=ans;
}
int solvet(vector<int> &weight,vector<int> &value,int n,int cap)
{
    vector<vector<int>> dp(n,vector<int>(cap+1,0));
    for(int w=weight[0];w<=cap;w++)
    {
    	if(weight[0]<=cap)
    	{
         	dp[0][w]=value[0];
        }
        else
        {
            dp[0][w]=0;
        }
    }
    for(int i=1;i<n;i++)
    {
       for(int w=0;w<=cap;w++)
       {
           int incl=0;
           if(weight[i]<=w)
           {
               incl=value[i]+dp[i-1][w-weight[i]];
           }
           int excl=dp[i-1][w];
           int ans=max(incl,excl);
           dp[i][w]=ans;
       }
    }
    return dp[n-1][cap];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    //vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
    //return solve(weight,value,n-1,maxWeight);
	return solvet(weight,value,n,maxWeight);
    // Write your code here
}
