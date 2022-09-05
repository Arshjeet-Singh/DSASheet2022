class Solution {
public:
    void solve(vector<int> nums,vector<vector<int>> &ans,int ind)
    {
        if(ind>=nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int j=ind;j<nums.size();j++)
        {
            swap(nums[ind],nums[j]);
            solve(nums,ans,ind+1);
            swap(nums[ind],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,ans,0);
        return ans;
    }
};
