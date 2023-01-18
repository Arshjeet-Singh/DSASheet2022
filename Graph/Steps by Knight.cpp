//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    int x1,x2,y1,y2;
	    x1=KnightPos[0];
	    x2=KnightPos[1];
	    y1=TargetPos[0];
	    y2=TargetPos[1];
	    if(x1==y1 and x2==y2)
	    {
	        return 0;
	    }
	    queue<pair<int,int>> q;
	    vector<vector<int>> vis(n,vector<int>(n,0));
	    q.push({x1-1,x2-1});
	    while(!q.empty())
	    {
	        auto t=q.front();
	        q.pop();
	        int i=t.first;
	        int j=t.second;
	        if(i+2>=0 && i+2<n && j+1>=0 && j+1<n && !vis[i+2][j+1])
	        {
	            vis[i+2][j+1]=vis[i][j]+1;
	            q.push({i+2,j+1});
	        }
	        if(i+2>=0 && i+2<n && j-1>=0 && j-1<n && !vis[i+2][j-1])
	        {
	            vis[i+2][j-1]=vis[i][j]+1;
	            q.push({i+2,j-1});
	        }
	        if(i-2>=0 && i-2<n && j+1>=0 && j+1<n && !vis[i-2][j+1])
	        {
	            vis[i-2][j+1]=vis[i][j]+1;
	            q.push({i-2,j+1});
	        }
	        if(i-2>=0 && i-2<n && j-1>=0 && j-1<n && !vis[i-2][j-1])
	        {
	            vis[i-2][j-1]=vis[i][j]+1;
	            q.push({i-2,j-1});
	        }
	        if(i+1>=0 && i+1<n && j+2>=0 && j+2<n && !vis[i+1][j+2])
	        {
	            vis[i+1][j+2]=vis[i][j]+1;
	            q.push({i+1,j+2});
	        }
	        if(i-1>=0 && i-1<n && j+2>=0 && j+2<n && !vis[i-1][j+2])
	        {
	            vis[i-1][j+2]=vis[i][j]+1;
	            q.push({i-1,j+2});
	        }
	        if(i+1>=0 && i+1<n && j-2>=0 && j-2<n && !vis[i+1][j-2])
	        {
	            vis[i+1][j-2]=vis[i][j]+1;
	            q.push({i+1,j-2});
	        }
	        if(i-1>=0 && i-1<n && j-2>=0 && j-2<n && !vis[i-1][j-2])
	        {
	            vis[i-1][j-2]=vis[i][j]+1;
	            q.push({i-1,j-2});
	        }
	    }
	    if(vis[y1-1][y2-1])
	    {
	        return vis[y1-1][y2-1];    
	    }
	    else
	    {
	        return -1;
	    }
	    // Code here
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
