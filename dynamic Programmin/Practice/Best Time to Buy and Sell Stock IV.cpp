class Solution {
public:
int so1(vector<int>& prices,int k)
{
    int n=prices.size();
    vector<vector<int>> curr(2,vector<int>(k+1,0));
    vector<vector<int>> next(2,vector<int>(k+1,0));
    // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            for(int l=1;l<=k;l++)
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
    return next[1][k];
}
int solve(int k, vector<int>& prices,int ind,int op)
{
    int n=prices.size();
    if(ind==n)
    {
        return 0;
    }
    if(op==2*k)
    {
        return 0;
    }
    int profit=0;
    if(op%2==0)
    {
        profit+=max(-prices[ind]+solve(k,prices,ind+1,op+1),solve(k,prices,ind+1,op));
    }
    else
    {
        profit+=max(prices[ind]+solve(k,prices,ind+1,op+1),solve(k,prices,ind+1,op));
    }
    return profit;
}
int solvem(int k, vector<int>& prices,int ind,int op,vector<vector<int>> &dp)
{
    int n=prices.size();
    if(ind==n)
    {
        return 0;
    }
    if(op==2*k)
    {
        return 0;
    }
    if(dp[ind][op]!=-1)
    {
        return dp[ind][op];
    }
    int profit=0;
    if(op%2==0)
    {
        profit+=max(-prices[ind]+solvem(k,prices,ind+1,op+1,dp),solvem(k,prices,ind+1,op,dp));
    }
    else
    {
        profit+=max(prices[ind]+solvem(k,prices,ind+1,op+1,dp),solvem(k,prices,ind+1,op,dp));
    }
    return dp[ind][op]=profit;
}
int solvet(int k, vector<int>& prices)
{
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int op=2*k-1;op>=0;op--)
        {
            int profit=0;
            if(op%2==0)
            {
                profit+=max(-prices[ind]+dp[ind+1][op+1],dp[ind+1][op]);
            }
            else
            {
                profit+=max(prices[ind]+dp[ind+1][op+1],dp[ind+1][op]);
            }
            dp[ind][op]=profit;
        }
    }
    return dp[0][0];
}
int so2(int k, vector<int>& prices)
{
    int n=prices.size();
    vector<int> curr(2*k+1,0);
    vector<int> next(2*k+1,0);
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int op=2*k-1;op>=0;op--)
        {
            int profit=0;
            if(op%2==0)
            {
                profit+=max(-prices[ind]+next[op+1],next[op]);
            }
            else
            {
                profit+=max(prices[ind]+next[op+1],next[op]);
            }
            curr[op]=profit;
        }
        next=curr;
    }
    return next[0];
}
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2*k,-1));
        // return solvem(k,prices,0,0,dp);
        return so2(k,prices);      
    }
};
