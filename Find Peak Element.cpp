class Solution {
    private:
    int helper(vector<int>& nums,int low,int high,int n)
    {
          int mid=low+(high-low)/2;
        if((mid==0 || nums[mid]>nums[mid-1]) && (mid==n-1 || nums[mid]>nums[mid+1]))
                {
                    return mid;
                }
         else if(mid>0 && nums[mid-1]>nums[mid])
                {
             return helper(nums,low,mid-1,n);
                    // high=mid-1;
                }
        else
        {
            return helper(nums,mid+1,high,n);
        }
    }
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        // int low=0,high=nums.size()-1;
        return helper(nums,0,n-1,n);
        
        

        
//         o(n)
        // int n=nums.size();
        // if(n==1)
        // {
        //     return 0;
        // }
        // int pe=-1;
        // for(int i=1;i<n-1;i++)
        // {
        //     if(nums[i]>nums[i-1] && nums[i]>nums[i+1])
        //     {
        //         pe=i;
        //         return pe;
        //     }
        // }
        // if(pe==-1)
        // {
        //     if(nums[0]>nums[1])
        //     {
        //         return 0;
        //     }
        //     else if(nums[n-1]>nums[n-2])
        //     {
        //         return n-1;
        //     }
        // }
        // return pe;
    }
};
