//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int> notes={1,2,5,10,20,50,100,200,500,2000};
        vector<int> ans;
        int n=notes.size()-1;
        int t=N;
        while(t>0 && n>=0)
        {
            if(t>=notes[n])
            {
                ans.push_back(notes[n]);
                t-=notes[n];
            }
            else
            {
                n--;
            }
        }
        return ans;
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
