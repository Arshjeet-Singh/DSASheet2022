//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool solve(int i,int n,int arr[],int t)
    {
        if(i>=n)
        {
            return 0;
        }
        if(t==0)
        {
            return 1;
        }
        bool in=solve(i+1,n,arr,t-arr[i]);
        bool ex=solve(i+1,n,arr,t);
        return in or ex;
    }
    bool solvem(int i,int n,int arr[],int t,vector<vector<int>> &dp)
    {
        if(i>=n)
        {
            return 0;
        }
        if(t<0)
        {
            return 0;
        }
        if(t==0)
        {
            return 1;
        }
        if(dp[i][t]!=-1)
        {
            return dp[i][t];
        }
        bool in=solvem(i+1,n,arr,t-arr[i],dp);
        bool ex=solvem(i+1,n,arr,t,dp);
        return dp[i][t]=in or ex;
    }
    bool solvet(int n,int arr[],int t)
    {
         vector<vector<int>> dp(n+1,vector<int>(t+1,0));
         for(int i=0;i<=n;i++)
         {
             dp[i][0]=1;
         }
         for(int i=n-1;i>=0;i--)
         {
             for(int tar=0;tar<=t;tar++)
             {
                bool in;
             if(tar-arr[i]>=0)
             {
                in=dp[i+1][tar-arr[i]];    
             }
        bool ex=dp[i+1][tar];
         dp[i][tar]=in or ex;    
             }
         }
         return dp[0][t];
    }
    bool so(int n,int arr[],int t)
    {
        vector<int> next(t+1,0);
        vector<int> curr(t+1,0);
        // for(int i=0;i<=n;i++)
        //  {
        //      [0]=1;
        //  }
        curr[0]=1;
        next[0]=1;
         for(int i=n-1;i>=0;i--)
         {
             for(int tar=0;tar<=t;tar++)
             {
                bool in=0;
             if(tar-arr[i]>=0)
             {
                in=next[tar-arr[i]];    
             }
        bool ex=next[tar];
         curr[tar]=in or ex;    
             }
             next=curr;
         }
         return next[t];
    }
    int equalPartition(int N, int arr[])
    {
        int s=0;
        for(int i=0;i<N;i++)
        {
            s+=arr[i];
        }
        if(s%2!=0)
        {
            return 0;
        }
        // vector<vector<int>> dp(N,vector<int>(s/2+1,-1));
        // return solvem(0,N,arr,s/2,dp);
        return so(N,arr,s/2);
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
