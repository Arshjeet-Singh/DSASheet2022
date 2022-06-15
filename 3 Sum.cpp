class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> v1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int rs=-nums[i];
            int j=i+1,k=nums.size()-1;
            while(j<k)
            {
                if(nums[j]+nums[k]==rs)
                {
                    v1.push_back(nums[i]);
                    v1.push_back(nums[j]);
                    v1.push_back(nums[k]);
                     v.push_back(v1);
                    while( j<k && nums[j]==v1[1])
                    {
                      j++;   
                    }
                     while( j<k && nums[k]==v1[2])
                    {
                       k--; 
                    }
                    v1.clear();
                }
                else if(nums[j]+nums[k]<rs)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }  
                while( i+1<nums.size() && nums[i]==nums[i+1])
                {
                    i++;
                }
        }
        return v;
    }
};
