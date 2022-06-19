class Solution {
public:
    int merge(vector<int>& nums,int low,int mid,int high)
    {
        int cnt=0;
        int j=mid+1;
        for(int i=low;i<=mid;i++)
        {
            while(j<=high && nums[i]>(2LL*nums[j]))
            {
                j++;
            }
            cnt+=(j-(mid+1));
        }
        vector<int> temp;
        int i=low;
        j=mid+1;
        while(i<=mid && j<=high)
        {
            if(nums[i]<=nums[j])
            {
                temp.push_back(nums[i++]);
            }
            else
            {
                 temp.push_back(nums[j++]);
            }
        }
        while(i<=mid)
        {
            temp.push_back(nums[i++]);   
        }
        while(j<=high)
        {
            temp.push_back(nums[j++]);   
        }
        for(int k=low;k<=high;k++)
        {
            nums[k]=temp[k-low];
        }
        return cnt;
    }
    int mergesort(vector<int>& nums,int low,int high)
    {
        if(low>=high)
        {
            return 0;
        }
        int mid=(low+high)/2;
        int inv=mergesort(nums,low,mid);
        inv+=mergesort(nums,mid+1,high);
        inv+=merge(nums,low,mid,high);
        return inv;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};
