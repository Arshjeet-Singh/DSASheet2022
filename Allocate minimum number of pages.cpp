//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    private:
    bool isvalid(int a[],int n,int m,int max)
    {
        int sum=0,student=1;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            if(sum>max)
            {
                student++;
                sum=a[i];
            }
            if(student>m)
            {
                return false;
            }
        }
        return true;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(N<M)
        {
            return -1;
        }
        int maxi=INT_MIN,sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
            maxi=max(maxi,A[i]);
        }
        int start=maxi,end=sum,res=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isvalid(A,N,M,mid))
            {
                res=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return res;
        //code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
