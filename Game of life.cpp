class Solution {
public:
    bool valid(vector<vector<int>>& board,int cr,int cl)
    {
        if((cr>=0 && cr<board.size()) && (cl>=0 && cl<board[0].size()))
        {
            return true;
        }
        return false;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> dirx{0,1,1,1,0,-1,-1,-1};
        vector<int> diry{1,1,0,-1,-1,-1,0,1};
          int m=board.size(),n=board[0].size();
         for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int live=0;
                for(int k=0;k<8;k++)
                {
                    int cr=dirx[k]+i;
                    int cl=diry[k]+j;
                    if(valid(board,cr,cl))
                    {
                        if(abs(board[cr][cl])==1)
                        {
                            live++;   
                        }
                    }
                }
                if(board[i][j]==1)
                {
                    if(live<2 || live>3)
                    {
                        board[i][j]=-1;
                    }
                }
                else
                {
                    if(live==3)
                    {
                        board[i][j]=2;
                    }
                }
            }
         }
         for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==-1)
                {
                    board[i][j]=0;
                }
                else if(board[i][j]==2)
                {
                     board[i][j]=1;
                }
                   
            }
         }
    }
       
};
