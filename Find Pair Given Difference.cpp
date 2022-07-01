// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    int i=0,j=size-1;
    sort(arr,arr+size);
    for(int i=0;i<size;i++)
    {
        int rem=arr[i]+n;
         int low=i+1,high=size-1;
         while(low<=high)
         {
             int mid=low+(high-low)/2;
             if(arr[mid]==rem)
             {
                 return true;
             }
             else if(arr[mid]<rem)
             {
                 low=mid+1;
             }
             else
             {
                 high=mid-1;
             }
         }
    }
    return false;
    //code
    
}
