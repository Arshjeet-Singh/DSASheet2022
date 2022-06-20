void help(int i,int n,int k,vector<int> &subset,vector<vector<int>> &ans)
{
    if(k==0)
    {
        ans.push_back(subset);
        return;
    }
    if(i>n)
    {
        return;
    }
    if(k>n-i+1)
    {
        return;
    }
      subset.push_back(i);
    help(i+1,n,k-1,subset,ans);
   subset.pop_back();
    help(i+1,n,k,subset,ans);
   
}
vector<vector<int>> combinations(int n, int k)
{
    vector<int> subset;
    vector<vector<int>> ans;
    help(1,n,k,subset,ans);
    return ans;
    // Write your code here.
}
