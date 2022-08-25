class Solution{
public:
    vector<vector<vector<int>>> dp;
    int helper(vector<string>& strs, int m, int n,int index)
    {
        if(index==strs.size())
        {
            return 0;
        }
        if(dp[m][n][index]!=-1)
        {
            return dp[m][n][index];
        }
        int zeros=count(strs[index].begin(),strs[index].end(),'0');
        int ones=count(strs[index].begin(),strs[index].end(),'1');
        if(m-zeros>=0 && n-ones>=0)
        {
            dp[m][n][index]= max(1+helper(strs,m-zeros,n-ones,index+1),helper(strs,m,n,index+1));
            return dp[m][n][index];
        }
        dp[m][n][index]=helper(strs,m,n,index+1);
        return dp[m][n][index];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.resize(m+1,vector<vector<int>>(n+1,vector<int>(strs.size(),-1)));
        return helper(strs,m,n,0);
    }
};
//iterative way bottom up approach also possible
