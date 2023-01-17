#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
long long int solvetab(vector<int> &nums,int i)
{
    vector<long long int> dp(i+1,0);
        dp[0]=nums[0];    
    for(int j=1;j<=i;j++)
    {
        dp[j]=max(dp[j-2]+nums[j],dp[j-1]);
    }
    return dp[i];
}
long long int solvetabbabbar(vector<int> &nums,int i)
{
    vector<int> dp(i,0);
        dp[0]=nums[0];
    for(int j=1;j<i;j++)
    {
        int incl;
        if(j-2<0)
        {
            incl=nums[j];    
        }
        else
        {
            incl=dp[j-2]+nums[j];
    
        }
                int excl=dp[j-1];
        dp[j]=max(incl,excl);
    }
    return dp[i-1];
}
long long int space(vector<int> &nums)
{
    int n=nums.size();
    long long int prev2=0;
    long long int prev1=nums[0];
    for(int i=1;i<n;i++)
    {
         long long int incl=prev2+nums[i];
        long long int excl=prev1+0;
        long long int ans=max(incl,excl);
         prev2=prev1;
        prev1=ans;
       
    }
    return prev1;
}
long long int houseRobber(vector<int>& valueInHouse)
{
   
    int n=valueInHouse.size();
    if(n==1)
    {
        return valueInHouse[0];
    }
     vector<int> first,second;
    for(int i=0;i<n;i++)
    {
        if(i!=n-1)
        {
            first.push_back(valueInHouse[i]);
        }
        if(i!=0)
        {
            second.push_back(valueInHouse[i]);
        }
    }
    return max(space(first),space(second));
    // Write your code here.
}
