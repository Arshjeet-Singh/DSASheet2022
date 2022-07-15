class Solution {
public:
    int maximumProduct(vector<int>& nums) {
   //nlogn soln
        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        // int maxp=INT_MIN;
        // maxp=max(maxp,nums[n-1]*nums[n-2]*nums[n-3]);
        // if(nums[0]<0 && nums[1]<0)
        // {
        //       maxp=max(maxp,nums[0]*nums[1]*nums[n-1]);
        // }
        // return maxp;
        //o(N) soln
         int n=nums.size();
        int maxi=INT_MIN,smax=INT_MIN,tmax=INT_MIN;
        int mini=INT_MAX,smin=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=maxi)
            {
                tmax=smax;
                smax=maxi;
                maxi=nums[i];
            }
            else if(nums[i]>=smax)
            {
                tmax=smax;
                smax=nums[i];
            }
            else if(nums[i]>=tmax)
            {
                tmax=nums[i];
            }
            if(nums[i]<=mini)
            {
                smin=mini;
                mini=nums[i];
            }
            else if(nums[i]<=smin)
            {
                smin=nums[i];
            }
        }
        int maxp=INT_MIN;
        if(mini<0 && smin<0)
        {
              maxp=max(maxp,mini*smin*maxi);
        }
        maxp=max(maxp,maxi*smax*tmax);
        
        return maxp;
        
    }
};
