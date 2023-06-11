//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool ispali(string s,int st,int e)
  {
    //   int st=0,e=s.size()-1;
      while(st<e)
      {
          if(s[st]!=s[e])
          {
              return false;
          }
          st++; e--;
      }
      return true;
  }
  void help(int ind,string s,vector<vector<string>> &ans,vector<string> &v)
  {
      if(ind==s.size())
      {
          ans.push_back(v);
          return;
      }
      for(int i=ind;i<s.size();i++)
      {
          if(ispali(s,ind,i))
          {
              v.push_back(s.substr(ind,i-ind+1));
              help(i+1,s,ans,v);
              v.pop_back();
          }
      }
  }
    vector<vector<string>> allPalindromicPerms(string S) {
    vector<vector<string>> ans;
    vector<string> v;
    help(0,S,ans,v);
    return ans;
        // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
