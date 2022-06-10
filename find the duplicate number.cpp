// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        vector<int> v;
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            if(m[arr[i]]==0)
            {
                m[arr[i]]=1;
            }
            else
            {
                m[arr[i]]++;
            }
        }
        for(auto &it:m)
        {
            if(it.second>1)
            {
                v.push_back(it.first);
            }
        }
        if(v.empty())
        {
            v.push_back(-1);
        }
        return v;
       /* vector<int> v;
        sort(arr,arr+n);
        for(int i=0;i<n;i++)
        {
            if(arr[i]==arr[i+1])
            {
                v.push_back(arr[i]);
            }
        }
        if(v.empty())
        {
            v.push_back(-1);
            return v;
        }
        else
        {
            return v;
        }*/
        // code here
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
