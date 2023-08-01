class Solution {
public:
void help(int n,int k,int ind,vector<int> &v,vector<vector<int>> &ans)
{

    if(v.size()==k)
    {
        ans.push_back(v);
        return;
    }
        if(ind>n)
    {
        return;
    }
    help(n,k,ind+1,v,ans);
    v.push_back(ind);
    help(n,k,ind+1,v,ans);
    v.pop_back();
}
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
         help(n,k,1,v,ans);
        return ans;
    }
};
