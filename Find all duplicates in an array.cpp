class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;
        int h=-1;
        for(int i=0;i<nums.size();i++)
        {
            h=nums[i];
            if(nums[abs(h)-1]<0)
            {
                v.push_back(abs(nums[i]));
            }
                nums[abs(h)-1]=-nums[abs(h)-1];
         }
        return v;
    }
};
