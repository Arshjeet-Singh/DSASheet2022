class Solution {
    private:
    // bool check(vector<int> &nums)
    // {
    //     int n=nums.size();
    //     for(int i=0;i<n-1;i++)
    //     {
    //         if(nums[i]!=nums[i+1])
    //         {
    //             return false;
    //         }
    //     }
    //     return true;
    // }
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int ans=0,mini=INT_MAX;
             for(int i=0;i<n;i++)
            {
                mini=min(nums[i],mini);
            }
             for(int i=0;i<n;i++)
            {
                ans+=nums[i]-mini;
            }
        return ans;
        // while(!check(nums))
        // {
        //      sort(nums.begin(),nums.end());
       
        //     ans++;
        // }
        return ans;
    }
};
