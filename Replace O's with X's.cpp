// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    void change(int n,int m,vector<vector<char>> &mat,int i,int j)
    {
        if(i>=0 && i<n && j>=0 && j<m && mat[i][j]=='O')
        {
             mat[i][j]='*';
        int ax[]={1,0,-1,0};
        int ay[]={0,-1,0,1};
        // int n=mat.size();
        // int m=mat[0].size();
        for(int k=0;k<4;k++)
        {
            int cx=i+ax[k];
            int cy=j+ay[k];
                change(n,m,mat,cx,cy);
        }
        }
        
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 ||i==n-1 || j==0 || j==m-1)
                {
                    if(mat[i][j]=='O')
                    {
                        change(n,m,mat,i,j);
                    }
                }
            }
        }
          for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++){

                if(mat[i][j] == '*'){

                    mat[i][j] = 'O';

                }else{

                    mat[i][j] = 'X';

                }

            }

        }
        return mat;
        // code here
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends
