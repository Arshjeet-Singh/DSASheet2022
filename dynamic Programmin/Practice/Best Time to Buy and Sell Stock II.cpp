class Solution {
public:
int solve(int ind,int buy,vector<int>& prices)
{
    if(ind==prices.size())
    {
        return 0;
    }
    int profit=0;
    if(buy)
    {
        profit+=max(-prices[ind]+solve(ind+1,0,prices),solve(ind+1,1,prices));
    }
    else
    {
        profit+=max(prices[ind]+solve(ind+1,1,prices),solve(ind+1,0,prices));
    }
    return profit;
}
int solvem(int ind,int buy,vector<int>& prices,vector<vector<int>> &dp)
{
    if(ind==prices.size())
    {
        return 0;
    }
    if(dp[ind][buy]!=-1)
    {
        return dp[ind][buy];
    }
    int profit=0;
    if(buy)
    {
        profit+=max(-prices[ind]+solvem(ind+1,0,prices,dp),solvem(ind+1,1,prices,dp));
    }
    else
    {
        profit+=max(prices[ind]+solvem(ind+1,1,prices,dp),solvem(ind+1,0,prices,dp));
    }
    return dp[ind][buy]=profit;
}
int solvet(vector<int>& prices)
{
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            int profit=0;
            if(buy)
            {
                profit+=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
            }
            else
            {
                profit+=max(prices[ind]+dp[ind+1][1],dp[ind+1][0]);
            }
             dp[ind][buy]=profit;
        }
    }
    return dp[0][1];
}
int so(vector<int>& prices)
{
    int n=prices.size();
    // vector<vector<int>> dp(n+1,vector<int>(2,0));
    vector<int> curr(2,0);
    vector<int> next(2,0);
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            int profit=0;
            if(buy)
            {
                profit+=max(-prices[ind]+next[0],next[1]);
            }
            else
            {
                profit+=max(prices[ind]+next[1],next[0]);
            }
             curr[buy]=profit;
        }
        next=curr;
    }
    return next[1];
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>> dp(n,vector<int>(2,-1));
        // return solvem(0,1,prices,dp);
        return so(prices);
    }
};
