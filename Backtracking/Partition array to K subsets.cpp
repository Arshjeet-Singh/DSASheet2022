//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
  bool solve(int a[], int n, int k,int ind,int cs,int rs,int buck,vector<int>&vis)
  {
      if(buck==k+1)
      {
          return true;
      }
      if(cs==rs)
      {
          return solve(a,n,k,0,0,rs,buck+1,vis);
      }
      if(cs>rs)
      {
          return false;
      }
      if(ind>=n)
      {
          return false;
      }
      if(vis[ind]==1)
      {
          return solve(a,n,k,ind+1,cs,rs,buck,vis);
      }
      else
      {
    //   cs+=a[ind];
        vis[ind]=1;
      bool in=solve(a,n,k,ind+1,cs+a[ind],rs,buck,vis);
    //   cs-=a[ind];
      vis[ind]=0;
      bool ex=solve(a,n,k,ind+1,cs,rs,buck,vis);
      return in|ex;    
      }
      
  }
    bool isKPartitionPossible(int a[], int n, int k)
    {
        int s=0;
        for(int i=0;i<n;i++)
        {
            s+=a[i];
        }
        if(s%k!=0)
        {
            return 0;
        }
        // int cnt=0;
        vector<int> vis(n,0);
        return solve(a,n,k,0,0,s/k,1,vis);

         //Your code here
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends
