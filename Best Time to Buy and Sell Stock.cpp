class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0;
        int mini=prices[0];
        for(int i=1;i<n;i++)
        {
            int diff=prices[i]-mini;
            profit=max(profit,diff);
            mini=min(mini,prices[i]);
        }
        return profit;
    }
};
// before watching the series soln is written below
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
      // Solutin in o(n^2)
        // for(int i=0;i<prices.size();i++)
        // {
        //     for(int j=i+1;j<prices.size();j++)
        //     {
        //         if(prices[j]>prices[i])
        //         {
        //             profit=max(profit,prices[j]-prices[i]);
        //         }
        //     }
        // }
      //o(n)
        int minprice=prices[0],maxpro=INT_MIN;
    for(int i=1;i<prices.size();i++)
    {
        minprice=min(minprice,prices[i]);
        maxpro=max(maxpro,prices[i]-minprice);
    }
        if(maxpro>0)
        {
            return maxpro;
        }
        else
        {
            return 0;
        }
    }
};
