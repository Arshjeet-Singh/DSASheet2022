class Solution {
public:
int solve(vector<int>& nums1, vector<int>& nums2,int i,bool swapped)
{
    if(i==nums1.size())
    {
        return 0;
    }
    int ans=INT_MAX;
    int prev1=nums1[i-1];
    int prev2=nums2[i-1];
    if(swapped)
    {
        swap(prev1,prev2);
    }
    //no swap
    if(prev1<nums1[i] && prev2<nums2[i])
    {
        ans=solve(nums1,nums2,i+1,0);
    }
    if(prev2<nums1[i] && prev1<nums2[i])
    {
        ans=min(ans,1+solve(nums1,nums2,i+1,1));
    }
    return ans;
}
int solvem(vector<int>& nums1, vector<int>& nums2,int i,bool swapped,vector<vector<int>> &dp)
{
    if(i==nums1.size())
    {
        return 0;
    }
    int ans=INT_MAX;
    int prev1=nums1[i-1];
    int prev2=nums2[i-1];
    if(dp[i][swapped]!=-1)
    {
        return dp[i][swapped];
    }
    if(swapped)
    {
        swap(prev1,prev2);
    }
    //no swap
    if(prev1<nums1[i] && prev2<nums2[i])
    {
        ans=solvem(nums1,nums2,i+1,0,dp);
        dp[i][swapped]=ans;
    }
    if(prev2<nums1[i] && prev1<nums2[i])
    {
        ans=min(ans,1+solvem(nums1,nums2,i+1,1,dp));
        dp[i][swapped]=ans;
    }
    return dp[i][swapped];
}
int solvet(vector<int>& nums1, vector<int>& nums2)
{
     vector<vector<int>> dp(nums1.size()+1,vector<int>(2,0));
    //  bool swapped=false;
     for(int i=nums1.size()-1;i>=1;i--)
     {
         for(int swapped=1;swapped>=0;swapped--)
         {
            int ans=INT_MAX;
            int prev1=nums1[i-1];
            int prev2=nums2[i-1];
            if(swapped)
            {
                swap(prev1,prev2);
            }
            //no swap
            if(prev1<nums1[i] && prev2<nums2[i])
            {
                ans=dp[i+1][0];
            }
            if(prev2<nums1[i] && prev1<nums2[i])
            {
                ans=min(ans,1+dp[i+1][1]);
                
            }
            dp[i][swapped]=ans;
         }   
     }
     return dp[1][0]; 
}
int so(vector<int>& nums1, vector<int>& nums2)
{
    //  vector<vector<int>> dp(nums1.size()+1,vector<int>(2,0));
     bool swapped=false;
    int swap=0,noswap=0,currswap=0,currnoswap=0;

     for(int i=nums1.size()-1;i>=1;i--)
     {
         for(int swapped=1;swapped>=0;swapped--)
         {
            int ans=INT_MAX;
            int prev1=nums1[i-1];
            int prev2=nums2[i-1];
            if(swapped)
            {
                int t=prev2;
                prev2=prev1;
                prev1=t;
                // swap(prev1,prev2);
            }
            //no swap
            if(prev1<nums1[i] && prev2<nums2[i])
            {
                ans=noswap;
            }
            if(prev2<nums1[i] && prev1<nums2[i])
            {
                ans=min(ans,1+swap);
                
            }
            if(swapped)
            {
                currswap=ans;
            }
            else
            {
                currnoswap=ans;
            }
         }
         swap=currswap;
         noswap=currnoswap;   
     }
     return min(swap,noswap); 
}
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        bool swapped=0;
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        // vector<vector<int>> dp(nums1.size()+1,vector<int>(2,-1));
        // return solvem(nums1,nums2,1,swapped,dp);
        return so(nums1,nums2);
    }
};
