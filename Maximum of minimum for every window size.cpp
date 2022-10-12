//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int> ans(n+1,0);
        vector<int> l(n+1,-1);
        vector<int> r(n+1,n);
        stack<int> sr,sl;
        for(int i=0;i<n;i++)
        {
            while(!sr.empty() && arr[sr.top()]>=arr[i])
            {
                sr.pop();
            }
            if(!sr.empty())
            {
                l[i]=sr.top();
            }
                
            sr.push(i);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!sl.empty() && arr[sl.top()]>=arr[i])
            {
                sl.pop();
            }
            if(!sl.empty())
            {
                r[i]=sl.top();    
            }
            sl.push(i);
        }
        for(int i=0;i<n;i++)
        {
            int len=r[i]-l[i]-1;
            ans[len]=max(ans[len],arr[i]);
        }
        for(int i=n-1;i>=1;i--)
        {
            ans[i]=max(ans[i],ans[i+1]);
        }
        vector<int> fans(n,0);
        for(int i=1;i<=n;i++)
        {
            fans[i-1]=ans[i];
        }
        // for(int k=1;k<=n;k++)
        // {
        //     deque<int> maxi(k);
        // for(int i=0;i<k;i++)
        // {
        //     while(!maxi.empty() && arr[i]<=arr[maxi.back()])
        //     {
        //         maxi.pop_back();
        //     }
        //     maxi.push_back(i);
        // }
        // int sum=0,maxim=INT_MIN;
        // maxim=max(maxim,arr[maxi.front()]);
        // // sum+=arr[maxi.front()];
        // for(int i=k;i<n;i++)
        // {
        //     while(!maxi.empty() && i-maxi.front()>=k)
        //     {
        //         maxi.pop_front();
        //     }
        //     while(!maxi.empty() && arr[i]<=arr[maxi.back()])
        //     {
        //         maxi.pop_back();
        //     }
        //     maxi.push_back(i);
        //     maxim=max(maxim,arr[maxi.front()]);
        // }
        // ans.push_back(maxim);    
        // }
        return fans;
        // Your code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
