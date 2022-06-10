class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,int> m,n;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    if(m[i]==0)
                    {
                        m[i]=1;
                    }
                    if(n[j]==0)
                    {
                        n[j]=1;
                    }
                }
            }
        }
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(m[i]==1 || n[j]==1)
                {
                    matrix[i][j]=0;
                }
            }
        }
    }
};
