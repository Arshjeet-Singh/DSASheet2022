//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    // int help(int i,int j,string s1, string s2, int n, int m)
    // {
    //     if(i>=n || j>=m)
    //     {
    //         return 0;
    //     }
    //     if(s1[i]==s2[j])
    //     {
    //         return 1+help(i+1,j+1,s1,s2,n,m);
    //     }
    //     else
    //     {
    //         return 0;
    //     }
    //     // int a=help(i+1,j,s1,s2,n,m);
    //     // int b=help(i,j+1,s1,s2,n,m);
    //     // return max(a,b);
    // }
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(S1[i-1]==S2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        return ans;
        // return help(0,0,S1,S2,n,m);
        // your code here
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
