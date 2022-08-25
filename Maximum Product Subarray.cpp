class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxsofar=nums[0];
        int maxending=nums[0];
        int minending=nums[0];
        int n=nums.size();
        // int p=1;
        // int currp=1;
        for(int i=1;i<n;i++)
        {
            // currp=currp*nums[i];
            int temp=max(maxending*nums[i],max(nums[i],minending*nums[i]));
            minending=min(minending*nums[i],min(maxending*nums[i],nums[i]));
            maxending=temp;
            maxsofar=max(maxsofar,maxending);
            // if()
        }
        return maxsofar;
    }
};
