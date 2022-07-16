class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
               int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
        // vector<int> v;
        // int n=matrix.size();
        // int dir=0;
        // int top=0,left=0,bottom=n-1,right=n-1;
        // while(top<=bottom && left<=right)
        // {
        //     if(dir==0)
        //     {
        //         for(int i=left;i<=right;i++)
        //         {
        //              v.push_back(matrix[top][i]);
        //         }
        //             top+=1;
        //     }
        //     else if(dir==1)
        //     {
        //         for(int i=top;i<=bottom;i++)
        //         {
        //              v.push_back(matrix[i][right]);
        //         }
        //         right-=1;
        //     }
        //     else if(dir==2)
        //     {
        //         for(int i=right;i>=left;i--)
        //         {
        //              v.push_back(matrix[bottom][i]);
        //         }
        //             bottom-=1;
        //     }
        //     else
        //     {
        //         for(int i=bottom;i>=top;i--)
        //         {
        //              v.push_back(matrix[i][left]);
        //         }
        //             left+=1;
        //     }
        //     dir=(dir+1)%4;
        // }
        // for(int i=0;i<v.size();i++)
        // {
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        // int k=0;
        // dir=1;
        // top=0;left=0;bottom=n-1;right=n-1;
        //  while(top<=bottom && left<=right)
        // {
        //     if(dir==0)
        //     {
        //         for(int i=left;i<=right;i++)
        //         {
        //              matrix[top][i]=v[k++];
        //             cout<<"top "<<top<<" i "<<i<<" k "<<k<<endl;
        //         }
        //             top+=1;
        //     }
        //     else if(dir==1)
        //     {
        //         for(int i=top;i<=bottom;i++)
        //         {
        //              matrix[i][right]=v[k++];
        //              cout<<"right "<<right<<" i "<<i<<" k "<<k<<endl;
        //         }
        //         right-=1;
        //     }
        //     else if(dir==2)
        //     {
        //         for(int i=right;i>=left;i--)
        //         {
        //              matrix[bottom][i]=v[k++];
        //              cout<<"bottom "<<bottom<<" i "<<i<<" k "<<k<<endl;
        //         }
        //             bottom-=1;
        //     }
        //     else if(dir==3)
        //     {
        //         for(int i=bottom;i>=top;i--)
        //         {
        //              matrix[left][i]=v[k++];
        //              cout<<"left "<<left<<" i "<<i<<" k "<<k<<endl;
        //         }
        //             left+=1;
        //     }
        //     dir=(dir+1)%4;
        // }
    }
};
