class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            if(m[nums[i]]==0)
            {
                m[nums[i]]=1;
            }
            else
            {
                m[nums[i]]++;
            }
        }
        int k=0;
        for(int i=0;i<nums.size();i++)
        {
            if(m[nums[i]]==1)
            {
                nums[k]=nums[i];
                k++;
                
            }
            else if(m[nums[i]]>1)
            {
                nums[k]=nums[i];
                k++;
                m[nums[i]]=0;
            }
        }
        return k;
    }
};
