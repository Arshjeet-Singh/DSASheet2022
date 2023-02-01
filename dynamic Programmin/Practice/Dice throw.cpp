//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long solvem(int n,int m,int x,vector<vector<long long>> &dp)
  {
      // n-> dice
      // m->faces
      // x->target
      if(x<0)
      {
          return 0;
      }
      if(x!=0 && n==0)
      {
          return 0;
      }
      if(x==0 && n!=0)
      {
          return 0;
      }
      if(x==0 && n==0)
      {
          return 1;
      }
      if(dp[n][x]!=-1)
      {
          return dp[n][x];
      }
    long long ans=0;
      for(int j=1;j<=m;j++)
      {
          ans=ans+solvem(n-1,m,x-j,dp);
      }
      return dp[n][x]=ans;
  }
  long long solvet(int n,int m,int x)
  {
      vector<vector<long long>> dp(n+1,vector<long long>(x+1,0));
      dp[0][0]=1;
      for(int i=1;i<=n;i++)
      {
          for(int t=1;t<=x;t++)
          {
                long long ans=0;
                  int j;
                  for(j=1;j<=m;j++)
                  {
                      if(t-j>=0)
                      {
                        ans=ans+dp[i-1][t-j];    
                      }
                  }
                 dp[i][t]=ans;    
          }
          
      }
      return dp[n][x];
  }
  long long so(int n,int m,int x)
  {
    //   vector<vector<long long>> dp(n+1,vector<long long>(x+1,0));
    vector<long long> prev(x+1,0);
    vector<long long> curr(x+1,0);
      prev[0]=1;
      for(int i=1;i<=n;i++)
      {
          for(int t=1;t<=x;t++)
          {
                long long ans=0;
                  int j;
                  for(j=1;j<=m;j++)
                  {
                      if(t-j>=0)
                      {
                        ans=ans+prev[t-j];    
                      }
                  }
                 curr[t]=ans;    
          }
          prev=curr;
      }
      return prev[x];
  }
    long long noOfWays(int M , int N , int X) {
        // vector<vector<long long>> dp(N+1,vector<long long>(X+1,-1));
        return so(N,M,X);
        // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends
