//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void solve(string str, int k,string &ans,int ind)
    {
        int n=str.size();
        if(k==0)
        {
            return;
        }
        char maxchar=str[ind];
        for(int i=ind+1;i<str.size();i++)
        {
            if(str[i]>maxchar)
            {
                maxchar=str[i];
            }
        }
        if(maxchar!=str[ind])
        {
            k--;    
        }
        for(int i=n-1;i>=ind;i--)
        {
            if(maxchar==str[i])
            {
                    swap(str[i],str[ind]);
                    if(str>ans)
                    {
                        ans=str;
                    }
                    solve(str,k,ans,ind+1);
                    swap(str[i],str[ind]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
        string ans=str;
        solve(str,k,ans,0);
        return ans;
       // code here.
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
