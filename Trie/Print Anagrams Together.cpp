//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++


// class trienode{
//     public:
//     char data;
//     trienode *children[26];
//     trienode(char x)
//     {
//         data=x;
//         for(int i=0;i<26;i++)
//         {
//             children[i]=0;
//         }
//     }
// };
// class trie{
//     public:
//     trienode *root=new trienode('/0');
//     void inserth(string s,trienode *root)
//     {
//         if(root==0)
//         {
//             return;
//         }
//         int temp=s[0]='a';
//         if(root->children[temp]!=0)
//         {
//             // root=root->children;
            
//         }
//         else
//         {
//             trienode *child=new trienode(s[0]);
//             root->children[temp]=child;
//         }
//         inserth(s.substr(1),root->children[temp])
//     }
//     void insert(string s)
//     {
//         inserth(s,root;)
//     }
// }

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& sl) {
        // trie t;
        // unordered_map<string,int> mp;
        // for(int i=0;i<sl.size();i++)
        // {
        //     mp[sl[i]]=1;
        //     // t.insert(sl[i]);
        // }
        // vector<vector<string>> ans;
        // for(int i=0;i<sl.size();i++)
        // {
        //     if(mp.find(sl[i])==mp.end())
        //     {
        //         continue;
        //     }
        //     unordered_map<char,int> mp1;
        //     for(int j=0;j<sl[i].size();j++)
        //     {
        //         mp1[sl[i][j]]++;
        //     }
            
        //     vector<string> v;
        //     v.push_back(sl[i]);
        //     for(int j=i+1;j<sl.size();j++)
        //     {
        //         unordered_map<char,int> mp2;
        //         for(int k=0;k<sl[j].size();k++)
        //         {
        //             mp2[sl[j][k]]++;
        //         }      
                
        //         if(mp1==mp2)
        //         {
        //             v.push_back(sl[j]);
        //             mp.erase(sl[j]);    
        //         }
        //     }
        //     mp.erase(sl[i]);
        //     ans.push_back(v);
        //     // t.insert(sl[i]);
        // }
        vector<vector<string> >ans;
        map<string,vector<string>> mp;
        for(int i=0;i<sl.size();i++)
        {
            string s=sl[i];
            sort(s.begin(),s.end());
            mp[s].push_back(sl[i]);
        }
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
        //code here
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

// } Driver Code Ends
