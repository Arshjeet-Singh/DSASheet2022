class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int temp=arr[i]-difference;
            int tans=0;
            if(dp.count(temp))
            {
                tans=dp[temp];
            }
            dp[arr[i]]=1+tans;
            ans=max(ans,dp[arr[i]]);
        }
        return ans;
    }
};
