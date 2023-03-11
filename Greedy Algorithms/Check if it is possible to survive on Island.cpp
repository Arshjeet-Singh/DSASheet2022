//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
       int ans=0;
    //   int numsunday=S/7;
       int buyingdays=S-S/7;
       if((S*M)%N==0)
       {
           ans=(S*M)/N;
       }
       else
       {
           ans=(S*M)/N+1;
       }
       if(ans<=buyingdays)
       {
           return ans;
       }
       else
       {
           return -1;
       }
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends
