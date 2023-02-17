class Solution {
public:
int so(vector<int>& prices,int fee)
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
                profit+=max(prices[ind]-fee+next[1],next[0]);
            }
             curr[buy]=profit;
        }
        next=curr;
    }
    return next[1];
}
    int maxProfit(vector<int>& prices, int fee) {
        return so(prices,fee);
    }
};
