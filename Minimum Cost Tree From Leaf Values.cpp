class Solution {
public:
    map<pair<int,int>,pair<int,int>> dp;
    pair<int,int> go(vector<int>& arr,int st,int en)
    {
        if(st==en)
        {
            return {arr[st],0};
        }
        if(dp.count({st,en}))
        {
            return dp[{st,en}];
        }
        int maxleaf=INT_MIN;
        int minsum=INT_MAX;
        for(int i=st;i<en;i++)
        {
            auto left=go(arr,st,i);
            auto right=go(arr,i+1,en);
            maxleaf=max(left.first,right.first);
            minsum=min(minsum,left.second+right.second+left.first*right.first);
            // minsum=min(minsum,)
            
        }
        return dp[{st,en}]={maxleaf,minsum};
       //  return dp[{st,en}];
    }
    int mctFromLeafValues(vector<int>& arr) {
        
        return go(arr,0,arr.size()-1).second;
    }
};
