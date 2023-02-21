class Solution {
public:
int solve(string a,string b,int i,int j)
{
    if(i==a.length())
    {
        return b.length()-j;
    }
    if(j==b.length())
    {
        return a.length()-i;
    }
    if(a[i]==b[j])
    {
        return solve(a,b,i+1,j+1);
    }
    int insert=1+solve(a,b,i,j+1);
    int del=1+solve(a,b,i+1,j);
    int rep=1+solve(a,b,i+1,j+1);
    return min(insert,min(del,rep));
}
int solvem(string a,string b,int i,int j,vector<vector<int>> &dp)
{
    if(i==a.length())
    {
        return b.length()-j;
    }
    if(j==b.length())
    {
        return a.length()-i;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(a[i]==b[j])
    {
        return solvem(a,b,i+1,j+1,dp);
    }
    int insert=1+solvem(a,b,i,j+1,dp);
    int del=1+solvem(a,b,i+1,j,dp);
    int rep=1+solvem(a,b,i+1,j+1,dp);
    return dp[i][j]=min(insert,min(del,rep));
}
int solvet(string a,string b)
{
    int n1=a.length();
    int n2=b.length();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    for(int j=0;j<b.length();j++)
    {
        dp[n1][j]=n2-j;
    }
    for(int i=0;i<a.length();i++)
    {
        dp[i][n2]=n1-i;
    }
    for(int i=n1-1;i>=0;i--)
    {
        for(int j=n2-1;j>=0;j--)
        {
            int ans=0;
            if(a[i]==b[j])
            {
                ans=dp[i+1][j+1];
            }
            else
            {
                int insert=1+dp[i][j+1];
                int del=1+dp[i+1][j];
                int rep=1+dp[i+1][j+1];
                ans=min(insert,min(del,rep));
            }
            dp[i][j]=ans;
        }
    }
    return dp[0][0];
}
int so(string a,string b)
{
    int n1=a.length();
    int n2=b.length();
    // vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    vector<int> curr(n2+1,0);
    vector<int> next(n2+1,0);
    for(int j=0;j<b.length();j++)
    {
        next[j]=n2-j;
    }
    // for(int i=0;i<a.length();i++)
    // {
        
    // }
    for(int i=n1-1;i>=0;i--)
    {
        for(int j=n2-1;j>=0;j--)
        {
            curr[n2]=n1-i;
            int ans=0;
            if(a[i]==b[j])
            {
                ans=next[j+1];
            }
            else
            {
                int insert=1+curr[j+1];
                int del=1+next[j];
                int rep=1+next[j+1];
                ans=min(insert,min(del,rep));
            }
            curr[j]=ans;
        }
        next=curr;
    }
    return next[0];
}
    int minDistance(string word1, string word2) {
        int n1=word1.length();
        int n2=word2.length();
        // vector<vector<int>> dp(n1,vector<int>(n2,-1));
        if(n1==0)
        {
            return n2;
        }
        if(n2==0)
        {
            return n1;
        }
        return so(word1,word2);   
    }
};
