//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int solve(int n, int a[],int curr,int prev)
    {
        if(curr>=n)
        {
            return 0;
        }
        int ex=solve(n,a,curr+1,prev);
        int in=0;
        if(prev==-1 ||  a[curr]>a[prev])
        {
            in=1+solve(n,a,curr+1,curr);
        }
        return max(in,ex);
    }
    int solvem(int n, int a[],int curr,int prev,vector<vector<int>> &dp)
    {
        if(curr==n)
        {
            return 0;
        }
        if(dp[curr][prev+1]!=-1)
        {
            return dp[curr][prev+1];
        }
        int ex=solvem(n,a,curr+1,prev,dp);
        int in=0;
        if(prev==-1 ||  a[curr]>a[prev])
        {
            in=1+solvem(n,a,curr+1,curr,dp);
        }
        return dp[curr][prev+1]=max(in,ex);
    }
    int solvet(int n, int a[])
    {
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int curr=n-1;curr>=0;curr--)
        {
            for(int prev=curr-1;prev>=-1;prev--)
            {
                int ex=dp[curr+1][prev+1];
                int in=0;
                if(prev==-1 ||  a[curr]>a[prev])
                {
                    in=1+dp[curr+1][curr+1];
                }
                dp[curr][prev+1]=max(in,ex);
            }
        }
        return dp[0][-1+1];
    }
    int so(int n, int a[])
    {
        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        vector<int> current(n+1,0);
        vector<int> next(n+1,0);
        for(int curr=n-1;curr>=0;curr--)
        {
            for(int prev=curr-1;prev>=-1;prev--)
            {
                int ex=next[prev+1];
                int in=0;
                if(prev==-1 ||  a[curr]>a[prev])
                {
                    in=1+next[curr+1];
                }
                current[prev+1]=max(in,ex);
            }
            next=current;
        }
        return next[-1+1];
    }
    int so2(int n, int a[])
    {
        if(n==0)
        {
            return 0;
        }
        vector<int> ans;
        ans.push_back(a[0]);
        for(int i=1;i<n;i++)  
        {
            if(a[i]>ans.back())
            {
                ans.push_back(a[i]);
            }
            else
            {
                int ind=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                ans[ind]=a[i];
            }
        }
        return ans.size();
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return solvem(n,a,0,-1,dp);
        return so2(n,a);
       // your code here
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends
