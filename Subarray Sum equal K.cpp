class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int prefix[n];
        int s=0,ans=0;
        unordered_map<int,int> um;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            prefix[i]=s;
        }
         for(int i=0;i<nums.size();i++)
        {
             if(prefix[i]==k)
             {
                 ans++;
             }
            if(um.find(prefix[i]-k)!=um.end())
            {
                ans+=um[prefix[i]-k];
            }
             um[prefix[i]]++;
        }
        return ans;
    }
};
