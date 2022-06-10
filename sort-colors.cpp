// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void swap(int *a,int *b)
    {
        int t=*a;
        *a=*b;
        *b=t;
    }
    void sort012(int a[], int n)
    {
        int low=0,mid=0,high=n-1;
        while(mid<=high)
        {
            if(a[mid]==1)
            {
                mid++;
            }
            else if(a[mid]==0)
            {
                swap(&a[mid],&a[low]);
                mid++; low++;
            }
            else
            {
                swap(&a[mid],&a[high]);
                 high--;
            }
        }
        /*for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                c1++;
            }
            else if(a[i]==1)
            {
                c2++;
            }
            else
            {
                c3++;
            }
        }
        int k=0;
        while(c1>0)
        {
            if(a[k]==0)
            {
                c1--;
            }
            else
            {
                int j=k+1;
                while(j<n)
                {
                    if(a[j]==0)
                    {
                        swap(&a[k],&a[j]);
                        c1--;
                    }
                    j++;
                }
            }
            k++;
        }
        while(c2>0)
        {
            if(a[k]==1)
            {
                c2--;
            }
            else
            {
                int j=k+1;
                while(j<n)
                {
                    if(a[j]==1)
                    {
                        swap(&a[k],&a[j]);
                        c2--;
                    }
                    j++;
                }
            }
            k++;
        }
        while(c3>0)
        {
            if(a[k]==2)
            {
                c3--;
            }
            else
            {
                int j=k+1;
                while(j<n)
                {
                    if(a[j]==2)
                    {
                        swap(&a[k],&a[j]);
                        c3--;
                    }
                    j++;
                }
            }
            k++;
        }*/
        // coode here 
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends
