class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>> &ans,vector<int> output,int ind)
    {
        if(ind==nums.size())
        {
            ans.push_back(output);
            return;
        }
        //exclude
        solve(nums,ans,output,ind+1);
        //include
        output.push_back(nums[ind]);
        solve(nums,ans,output,ind+1);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(nums,ans,output,0);
        return ans;
    }
};
