// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow(string s, string p)
    {
        int a[256]={0};
        int count=0;
        for(int i=0;i<p.length();i++)
        {
            if(a[p[i]]==0)
            {
                count++;
            }
            a[p[i]]++;
        }
        int res=INT_MAX;
        int start=0;
        int i=0,j=0;
        while(j<s.length())
        {
            a[s[j]]--;
            if(a[s[j]]==0)
            {
                count--;
            }
            if(count==0)
            {
                while(count==0)
                {
                    if(j-i+1<res)
                    {
                        res=j-i+1;
                        start=i;
                    }
                    a[s[i]]++;
                    if(a[s[i]]==1)
                    {
                        count++;
                    }
                    i++;
                }
            }
            j++;
        }
        if(res!=INT_MAX)
        {
            return s.substr(start,res);
        }
       return "-1";
    }
        
        // Your code here
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
