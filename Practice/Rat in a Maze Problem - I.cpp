//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool safe(vector<vector<int>> &m,vector<vector<int>> visited,int x,int y,int n)
    {
        if((x>=0 && x<n)&&(y>=0 && y<n)&&(!visited[x][y])&&m[x][y]==1)
        {
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>> &m,vector<string> &ans,vector<vector<int>> &visited,string output,int n,int x,int y)
    {
        if(x==n-1 && y==n-1)
        {
            ans.push_back(output);
            return;
        }
        visited[x][y]=1;
        //down
        int nx=x+1;
        int ny=y;
        if(safe(m,visited,nx,ny,n))
        {
              output.push_back('D');
              solve(m,ans,visited,output,n,nx,ny);

            // visited[nx][ny]=1;
          
            output.pop_back();
        }
         nx=x;
         ny=y-1;
        if(safe(m,visited,nx,ny,n))
        {
            // visited[nx][ny]=1;
            output.push_back('L');
            solve(m,ans,visited,output,n,nx,ny);
            output.pop_back();
        }
         nx=x;
         ny=y+1;
        if(safe(m,visited,nx,ny,n))
        {
            // visited[nx][ny]=1;
            output.push_back('R');
            solve(m,ans,visited,output,n,nx,ny);
            output.pop_back();
        }
         nx=x-1;
        ny=y;
        if(safe(m,visited,nx,ny,n))
        {
            // visited[nx][ny]=1;
            output.push_back('U');
            solve(m,ans,visited,output,n,nx,ny);
            output.pop_back();
        }
        visited[x][y]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0]==0)
        {
            return ans;
        }
        vector<vector<int>> visited=m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                visited[i][j]=0;
            }
        }
        solve(m,ans,visited,"",n,0,0);
        return ans;
        // Your code goes here
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
