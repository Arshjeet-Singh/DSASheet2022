#include <bits/stdc++.h> 
int solve(vector<int> &nums,int i)
{
    if(i==0)
    {
        return nums[i];
    }
    if(i<0)
    {
        return 0;
    }
    int incl=solve(nums,i-2)+nums[i];
    int excl=solve(nums,i-1)+0;
    return max(incl,excl);
}
int solvem(vector<int> &nums,int i,vector<int> &dp)
{
    if(i==0)
    {
        return nums[i];
    }
    if(i<0)
    {
        return 0;
    }
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    int incl=solvem(nums,i-2,dp)+nums[i];
    int excl=solvem(nums,i-1,dp)+0;
    dp[i]=max(incl,excl);
    return dp[i];
}
int solvetab(vector<int> &nums,int i)
{
    vector<int> dp(i+1,0);
    	dp[0]=nums[0];    
    /*if(i==1)
    {
        dp[1]=max(dp[0],dp[1]);
    }*/
    for(int j=1;j<=i;j++)
    {
        dp[j]=max(dp[j-2]+nums[j],dp[j-1]);
    }
    return dp[i];
}
int solvetabbabbar(vector<int> &nums,int i)
{
    vector<int> dp(i,0);
        dp[0]=nums[0];    
    /*if(i==1)
    {
        dp[1]=max(dp[0],dp[1]);
    }*/
    for(int j=1;j<i;j++)
    {
        dp[j]=max(dp[j-2]+nums[j],dp[j-1]);
    }
    return dp[i-1];
}
int space(vector<int> &nums)
{
    int n=nums.size();
    int prev2=0;
    int prev1=nums[0];
    for(int i=1;i<n;i++)
    {
 		int incl=prev2+nums[i];
        int excl=prev1+0;
        int ans=max(incl,excl);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    //int ans=solve(nums,n-1);
    //memoisation
    //vector<int> dp(n+1,-1);
    //int ans=solvem(nums,n-1,dp);
    //return ans;
    //tabulation
 	//own
    //int ans=solvetab(nums,n-1);
    int ans=space(nums);
    return ans;
    // Write your code here.
}
