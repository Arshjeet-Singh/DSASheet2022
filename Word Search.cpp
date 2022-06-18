class Solution {
public:
    bool dfs(int i,int j,vector<vector<char>>& board,vector<vector<bool>>& visited,string check,int idx)
    {
        if(idx==check.size())
        {
            return true;
        }
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || visited[i][j]==1)
        {
            return false;
        }
        if(board[i][j]!=check[idx])
        {
            return false;
        }
        visited[i][j]=1;
        if(dfs(i-1,j,board,visited,check,idx+1) || dfs(i+1,j,board,visited,check,idx+1)
          || dfs(i,j-1,board,visited,check,idx+1) ||dfs(i,j+1,board,visited,check,idx+1))
        {
            return true;
        }
        visited[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    vector<vector<bool>>visited(n,vector<bool>(m,false));
                     if(dfs(i,j,board,visited,word,0))
                     {
                         return true;
                     }
                }
            }
        }
        return false;
    }
};
