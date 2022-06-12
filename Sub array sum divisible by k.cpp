// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	long long subCount(long long arr[], int N, long long K)
	{
	    long long ans=0;
	    int mod[K];
	    for(int i=0;i<K;i++)
	    {
	        mod[i]=0;
	    }
	    int cs=0;
	    for(int i=0;i<N;i++)
	    {
	        cs+=arr[i];
	        mod[((cs%K)+K)%K]++;
	    }
	    for(int i=0;i<K;i++)
	    {
	        if(mod[i]>0)
	        {
	            ans+=(mod[i]*(mod[i]-1))/2;
	        }
	    }
	    ans+=mod[0];
	    return ans;
	    // Your code goes here
	}



};


// { Driver Code Starts.

int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
       	long long k;
		cin>>n >> k;
		long long a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
        

        Solution ob;
        cout << ob.subCount(a, n, k);
	    cout << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
