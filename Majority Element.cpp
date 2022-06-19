class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,mele=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==mele)
            {
                count++;
            }
            else
            {
                count--;
                if(count==0)
                {
                    mele=nums[i];
                    count=1;
                }
            }
        }
        return mele;
//         unordered_map<int,int> um;
//         for(int i=0;i<nums.size();i++)
//         {
//             um[nums[i]]++;
//         }
        
//         int f=(nums.size())/2;
//         for(int it=0;it<um.size();it++)
//         {
//             if(um[it]>f)
//             {
//                 return it;
//             }
//         }
//         return 0;
        
    }
};
