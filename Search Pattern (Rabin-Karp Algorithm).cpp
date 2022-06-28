// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            int q=INT_MAX;
            vector<int> v;
            int n=txt.length();
            int m=pat.length();
            int h=1;
             int d=256;
            for(int i=0;i<m-1;i++)
            {
                h=(h*d)%q;
            }
            int p=0,t0=0;
            for(int i=0;i<m;i++)
            {
                p=(d*p+pat[i])%q;
                t0=(d*t0+txt[i])%q;
            }
            for(int s=0;s<=n-m;s++)
            {
                if(p==t0)
                {
                    int i=0;
                    for(i=0;i<m;i++)
                    {
                        if(pat[i]==txt[s+i])
                        {
                            
                        }
                        else
                        {
                            break;
                        }
                    }
                    if(i==m)
                    {
                        v.push_back(s+1);
                    }
                }
                if(s<n-m)
                {
                    t0=(d*(t0-txt[s]*h)+txt[s+m])%q;
                }
            }
            if(v.size()==0)
            {
                v.push_back(-1);
            }
            return v;
            //code here.
        }
     
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends
