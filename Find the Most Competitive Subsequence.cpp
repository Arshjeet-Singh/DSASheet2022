class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        // priority_queue<int> pq;
        // for(int i=0;i<nums.size();i++)
        // {
        //     pq.push(nums[i]);
        //     if(pq.size()>k)
        //     {
        //         pq.pop();
        //     }
        // }
        vector<int> v;
        int rem=nums.size()-k;
        for(int i=0;i<nums.size();i++)
        {
            while(v.size()>0 &&rem && nums[i]<v.back())
            {
                v.pop_back();
                rem--;
            }
            v.push_back(nums[i]);
        }
        while(v.size() && rem)
        {
            v.pop_back();
            rem--;
        }
        return v;  
    }
};
