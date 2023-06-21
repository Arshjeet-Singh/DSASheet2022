class Solution {
public:
    int help(int i,int j,vector<int>& nums1, vector<int>& nums2)
    {
        if(i>=nums1.size() || j>=nums2.size())
        {
            return 0;
        }
        if(nums1[i]==nums2[j])
        {
            return 1+help(i+1,j+1,nums1,nums2);
        }
        else
        {
            return 0;
        }
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // return help(0,0,nums1,nums2);
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int ans=0;
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(nums1[i-1]==nums2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=0;
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
