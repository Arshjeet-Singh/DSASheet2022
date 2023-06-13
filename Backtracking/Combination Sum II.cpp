class Solution {
public:
void help(int ind,vector<int>& candidates, int target,vector<vector<int>> &ans,vector<int> &v)
{
    if(target==0)
    {
        ans.push_back(v);
        return;
    }
    for(int i=ind;i<candidates.size();i++)
    {
        if(i>ind && candidates[i]==candidates[i-1])
        {
            continue;
        }
        if(candidates[i]>target)
        {
            break;
        }
        v.push_back(candidates[i]);
        help(i+1,candidates,target-candidates[i],ans,v);
        v.pop_back();
    }
    // if(ind==candidates.size())
    // {
    //     if(target==0)
    //     {
    //         sort(v.begin(),v.end());
    //         ans.insert(v); 
    //     }
    //      return;
    //     // return;
    // }
    // if(candidates[ind]<=target)
    // {
    //     v.push_back(candidates[ind]);
    //     help(ind+1,candidates,target-candidates[ind],ans,v);
    //     v.pop_back();
    // }
    // help(ind+1,candidates,target,ans,v);
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        help(0,candidates,target,ans,v);
        return ans;
    }
};
