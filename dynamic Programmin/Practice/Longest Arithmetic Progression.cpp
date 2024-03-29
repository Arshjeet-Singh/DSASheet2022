//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
int solve(int i,int diff,int A[])
{
    if(i<0)
    {
        return 0;
    }
    int ans=0;
    for(int j=i-1;j>=0;j--)
    {
        if(A[i]-A[j]==diff)
        {
            ans=max(ans,1+solve(j,diff,A));
        }
    }
    return ans;
}
int solvem(int i,int diff,int A[],unordered_map<int,int> dp[])
{
    if(i<0)
    {
        return 0;
    }
    if(dp[i].count(diff))
    {
        return dp[i][diff];
    }
    int ans=0;
    for(int j=i-1;j>=0;j--)
    {
        if(A[i]-A[j]==diff)
        {
            ans=max(ans,1+solvem(j,diff,A,dp));
        }
    }
    return dp[i][diff]=ans;
}

    int lengthOfLongestAP(int A[], int n) {
        if(n<=2)
        {
            return n;
        }
        unordered_map<int,int> dp[n+1];
        int ans=0;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=i+1;j<n;j++)
        //     {
        //         ans=max(ans,2+solvem(i,A[j]-A[i],A,dp));
        //     }
        // }
        //tabulation
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff=A[i]-A[j];
                int cnt=1;
                if(dp[j].count(diff))
                {
                    cnt=dp[j][diff];
                }
                dp[i][diff]=1+cnt;
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans;
        // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
