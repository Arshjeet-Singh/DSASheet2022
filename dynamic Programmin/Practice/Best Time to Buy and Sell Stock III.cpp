class Solution {
public:
int solve(int ind,int buy,vector<int>& prices,int l)
{
    if(ind==prices.size())
    {
        return 0;
    }
    if(l==0)
    {
        return 0;
    }
    int profit=0;
    if(buy)
    {
        profit+=max(-prices[ind]+solve(ind+1,0,prices,l),solve(ind+1,1,prices,l));
    }
    else
    {
        profit+=max(prices[ind]+solve(ind+1,1,prices,l-1),solve(ind+1,0,prices,l));
    }
    return profit;
}
int solvem(int ind,int buy,vector<int>& prices,int l,vector<vector<vector<int>>> &dp)
{
    if(ind==prices.size())
    {
        return 0;
    }
    if(l==0)
    {
        return 0;
    }
    if(dp[ind][buy][l]!=-1)
    {
        return dp[ind][buy][l];
    }
    int profit=0;
    if(buy)
    {
        profit+=max(-prices[ind]+solvem(ind+1,0,prices,l,dp),solvem(ind+1,1,prices,l,dp));
    }
    else
    {
        profit+=max(prices[ind]+solvem(ind+1,1,prices,l-1,dp),solvem(ind+1,0,prices,l,dp));
    }
    return dp[ind][buy][l]=profit;
}
int solvet(vector<int>& prices)
{
    int n=prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            for(int l=1;l<=2;l++)
            {
                int profit=0;
                if(buy)
                {
                    profit+=max(-prices[ind]+dp[ind+1][0][l],dp[ind+1][1][l]);
                }
                else
                {
                    profit+=max(prices[ind]+dp[ind+1][1][l-1],dp[ind+1][0][l]);
                }
                dp[ind][buy][l]=profit;
            }
        }
    }
    return dp[0][1][2];
}
int so(vector<int>& prices)
{
    int n=prices.size();
    vector<vector<int>> curr(2,vector<int>(3,0));
    vector<vector<int>> next(2,vector<int>(3,0));
    // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            for(int l=1;l<=2;l++)
            {
                int profit=0;
                if(buy)
                {
                    profit+=max(-prices[ind]+next[0][l],next[1][l]);
                }
                else
                {
                    profit+=max(prices[ind]+next[1][l-1],next[0][l]);
                }
                curr[buy][l]=profit;
            }
          
        }
          next=curr;
    }
    return next[1][2];
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        // return solvem(0,1,prices,2,dp);
        return so(prices);
    }
};
