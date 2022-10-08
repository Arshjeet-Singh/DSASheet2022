//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		  //  stack<char> s;
		  queue<char> q;
		  unordered_map<char,int> mp;
		    string ans="";
		     for(int i=0;i<A.length();i++)
		    {
		        mp[A[i]]++;
		            q.push(A[i]);
		        while(!q.empty())
		        {
		            if(mp[q.front()]>1)
    		        {
    		            q.pop();
    		        }
    		        else
    		        {
    		            ans+=q.front();
    		            break;
    		        }
		        }
		        if(q.empty())
		        {
		            ans+='#';
		        }
		    }
		  return ans;
		    // Code here
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
