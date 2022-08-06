class Solution {
public:
    string leftjustify(vector<string>& words,int diff,int i,int j)
    {
        int spacesright=diff-(j-i-1);
        string res=words[i];
        for(int k=i+1;k<j;k++)
        {
            res=res+" "+words[k];
        }
        for(int l=0;l<spacesright;l++)
        {
            res+=" ";
        }
        return res;
    }
    string middlejustify(vector<string>& words,int diff,int i,int j)
    {
        int spacesneeded=j-i-1;
        int spaces=diff/spacesneeded;
        int extraspaces=diff%spacesneeded;
        string res=words[i];
        for(int k=i+1;k<j;k++)
        {
            int spacestoapply=spaces+(extraspaces-- > 0 ? 1 : 0);
            for(int l=0;l<spacestoapply;l++)
            {
                res+=" ";
                
            }
            res+=words[k];
                // res+=" "
        }
        return res;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
       vector<string> v;
        int i=0,n=words.size();
        while(i<n)
        {
            int j=i+1;
            int llen=words[i].length();
            while(j<n && llen+words[j].length()+(j-i-1)<maxWidth)
            {
                llen+=words[j].length();
                j++;
            }
            int diff=maxWidth-llen;
            int numwords=j-i;
            if(numwords==1 || j>=n)
            {
                v.push_back(leftjustify(words,diff,i,j));
            }
            else
            {
                v.push_back(middlejustify(words,diff,i,j));
            }
            i=j;
        }
        return v;
    }
    
    
    
    
    
    
    
    
    
    
    // int cost[words.size()][words.size()];
//         int n=words.size();
//         for(int i=0;i<n;i++)
//         {
//             cost[i][i]=maxWidth-words[i].length();
//             for(int j=i+1;j<n;j++)
//             {
//                 cost[i][j]=cost[i][j-1]-words[j].length()-1;
//             }
//         }
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i;j<n;j++)
//             {
//                 if(cost[i][j]<0)
//                 {
//                     cost[i][j]=INT_MAX;
//                 }
//                 else
//                 {
//                     cost[i][j]=(cost[i][j]*cost[i][j]);
//                 }
//             }
//         }
//         int mincost[n];
//         int result[n];
//         for(int i=n-1;i>=0;i--)
//         {
//             mincost[i]=cost[i][n-1];
//             result[i]=n;
//             for(int j=n-1;j<i;j--)
//             {
//                 if(cost[i][j-1]==INT_MAX)
//                 {
//                     continue;
//                 }
//                 if(mincost[i]>mincost[j]+cost[i][j-1])
//                 {
//                     mincost[i]=mincost[j]+cost[i][j-1];
//                     result[i]=j;
//                 }
//             }
            
//         }
//         int i=0;
//         int j;
//         vector<string> v;
//         do{
//             j=result[i];
//             for(int k=i;k<j;k++)
//             {
//                 v.push_back(words[k]+" ");
//             }
//             v.push_back("\n");
//             i=j;
//         }while(j<n);
//         return v;
};
