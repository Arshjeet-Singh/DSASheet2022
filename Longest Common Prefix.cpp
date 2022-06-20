class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int f=-1;
        if(strs.size()==1)
        {
            return strs[0];
        }
        for(int j=0;j<strs[0].length();j++)
        {
            f=-1;
             for(int i=1;i<strs.size();i++)
            {
                if(strs[0][j]==strs[i][j])
                {
                    
                    f=1;
                }
                 else
                 {
                     f=0;
                     break;
                 }
            }
            if(f==1)
            {
                ans+=strs[0][j];
            }
            else
            {
                break;
            }
        }
       return ans;
    }
};
