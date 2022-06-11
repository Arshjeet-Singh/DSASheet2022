class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int right=0,left=0,temp;
        while(right<nums.size())
        {
            if(nums[right]==0)
            {
                right++;
            }
            else
            {
                temp=nums[left];
                nums[left]=nums[right];
                nums[right]=temp;
                left++;
                right++;
            }
        }
        // int i=0,j=0,n=nums.size();
        // while(i<n && j<n)
        // {
        //     while(i<n && nums[i]!=0 )
        //     {
        //         i++;
        //     }
        //     while(j<n && nums[j]==0 )
        //     {
        //         j++;
        //     }
        //     if(j<n && i<n)
        //     {
        //         nums[i]=nums[j];
        //         nums[j]=0;
        //     }
        // }   
    }
};
