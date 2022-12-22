#include <bits/stdc++.h> 
void addsolution(vector<vector<int>>&board,vector<vector<int>>&ans,int n)
{
    vector<int> temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}
bool safe(int row,int col,vector<vector<int>>&board,int n)
{
    int x=row,y=col;
    while(y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        y--;
    }
    x=row;
    y=col;
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--; y--;
    }
    x=row;
    y=col;
    while(x<n && y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x++; y--;
    }
    return true;
}
void solve(int col,vector<vector<int>>&board,vector<vector<int>>&ans,int n)
{
    if(col==n)
    {
        addsolution(board,ans,n);
        return;
    }
    for(int row=0;row<n;row++)
    {
        if(safe(row,col,board,n))
        {
            board[row][col]=1;
            solve(col+1,board,ans,n);
            board[row][col]=0;
        }    
    }
    
}
vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> ans;
    vector<vector<int>> board(n,vector<int>(n,0));
    solve(0,board,ans,n);
    return ans;
	// Write your code here
	
}
