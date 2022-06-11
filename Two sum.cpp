class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        int j=nums.size();
        unordered_map<int,int> umap;
        for(int i=0;i<j;i++)
        {
            int n1=target-nums[i];
            auto it=umap.find(n1);
            if(it!=umap.end())
            {
                v.push_back(i);
                v.push_back(it->second);
                break;
            }
            umap[nums[i]]=i;
        }
        return v;
        // for(int i=0;i<j;i++)
        // {
        //     umap[nums[i]]=1;
        // }
        // for(int i=0;i<j;i++)
        // {
        //     if(umap[target-nums[i]]>0)
        //     {
        //         v.push_back(i);
        //         break;
        //     }
        // }
        //  for(int i=0;i<j;i++)
        // {
        //     if(nums[i]==(target-nums[v[0]]) && i!=v[0])
        //     {
        //          v.push_back(i);
        //     }
        // }
        // return v;
    }
};
