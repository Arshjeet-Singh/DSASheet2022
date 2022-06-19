class Solution {
public:
    int strStr(string haystack, string needle) {
        int f=-1,ind=-1;
        for(int i=0;i<haystack.length();i++)
        {
            if(needle[0]==haystack[i])
            {
                for(int j=0;j<needle.length();j++)
                {
                    if(needle[j]==haystack[i+j])
                    {
                        f=1;
                    }
                    else
                    {
                        f=-1;
                        break;
                    }
                }
                if(f==1)
                {
                    ind=i;
                    return ind;
                }
            }
        }
        return ind;
    }
};
