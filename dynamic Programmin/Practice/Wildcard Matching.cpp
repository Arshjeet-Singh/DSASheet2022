class Solution {
public:
bool solve(string s, string p,int i,int j)
{
    if(i<0 && j<0)
    {
        return true;
    }
    if(i>=0 && j<0)
    {
        return false;
    }
    if(j>=0 && i<0)
    {
        for(int k=0;k<=j;k++)
        {
            if(p[k]!='*')
            {
                return false;
            }
        }
        return true;
    }
    if(p[j]==s[i] || p[j]=='?')
    {
        return solve(s,p,i-1,j-1);
    }
    else if(p[j]=='*')
    {
        return solve(s,p,i-1,j)||solve(s,p,i,j-1);
    }
    return false;
}
bool solvem(string &s, string &p,int i,int j,vector<vector<int>> &dp)
{
    if(i<0 && j<0)
    {
        return true;
    }
    if(i>=0 && j<0)
    {
        return false;
    }
    if(j>=0 && i<0)
    {
        for(int k=0;k<=j;k++)
        {
            if(p[k]!='*')
            {
                return false;
            }
        }
        return true;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    // bool ans=false;
    if(p[j]==s[i] || p[j]=='?')
    {
        dp[i][j]=solvem(s,p,i-1,j-1,dp);
    }
    else if(p[j]=='*')
    {
        dp[i][j]=solvem(s,p,i-1,j,dp)||solvem(s,p,i,j-1,dp);
    }
    else
    {
        dp[i][j]=false;
    }
    return dp[i][j];
}
bool solvem2(string &s, string &p,int i,int j,vector<vector<int>> &dp)
{
    if(i==0 && j==0)
    {
        return true;
    }
    if(i>0 && j==0)
    {
        return false;
    }
    if(j>0 && i==0)
    {
        for(int k=1;k<=j;k++)
        {
            if(p[k-1]!='*')
            {
                return false;
            }
        }
        return true;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    // bool ans=false;
    if(p[j-1]==s[i-1] || p[j-1]=='?')
    {
        dp[i][j]=solvem2(s,p,i-1,j-1,dp);
    }
    else if(p[j-1]=='*')
    {
        dp[i][j]=solvem2(s,p,i-1,j,dp)||solvem2(s,p,i,j-1,dp);
    }
    else
    {
        dp[i][j]=false;
    }
    return dp[i][j];
}
bool solvet(string s, string p)
{
    int n1=s.length(),n2=p.length();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    dp[0][0]=1;
    for(int j=1;j<=n2;j++)
    {
        bool flag=true;
        for(int k=1;k<=j;k++)
        {
            if(p[k-1]!='*')
            {
                flag=false;
                break;
            }
        }
        dp[0][j]=flag;
    }
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            if(p[j-1]==s[i-1] || p[j-1]=='?')
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else if(p[j-1]=='*')
            {
                dp[i][j]=dp[i-1][j]||dp[i][j-1];
            }
            else
            {
                dp[i][j]=false;
            }
        }
    }
    return dp[n1][n2];
}
bool so(string s, string p)
{
    int n1=s.length(),n2=p.length();
    // vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    vector<int> curr(n2+1,0);
    vector<int> prev(n2+1,0);
    prev[0]=1;
    for(int j=1;j<=n2;j++)
    {
        bool flag=true;
        for(int k=1;k<=j;k++)
        {
            if(p[k-1]!='*')
            {
                flag=false;
                break;
            }
        }
        prev[j]=flag;
    }
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            if(p[j-1]==s[i-1] || p[j-1]=='?')
            {
                curr[j]=prev[j-1];
            }
            else if(p[j-1]=='*')
            {
                curr[j]=prev[j]||curr[j-1];
            }
            else
            {
                curr[j]=false;
            }
        }
        prev=curr;
    }
    return prev[n2];
}
    bool isMatch(string s, string p) {
        int n1=s.length(),n2=p.length();
        // vector<vector<int>> dp(n1,vector<int>(n2,-1));
        //  vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        // return solvem(s,p,n1-1,n2-1,dp);
        // return solvem2(s,p,n1,n2,dp);
        return so(s,p);
    }
};
