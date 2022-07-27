class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length(),m=t.length();
        int a[256]={0};
        int count=0;
        for(int i=0;i<m;i++)
        {
            if(a[t[i]]==0)
            {
                count++;
            }
            a[t[i]]++;
        }
        int i=0,j=0;
        int res=INT_MAX;
        int start=0;
        while(j<n)
        {
            a[s[j]]--;
            if(a[s[j]]==0)
            {
                count--;
            }
            if(count==0)
            {
                while(count==0)
                {
                    if(j-i+1<res)
                    {
                        start=i;
                        res=j-i+1;
                    }
                    a[s[i]]++;
                    if(a[s[i]]==1)
                    {
                        count++;
                    }
                    i++;   
                }
            }
            j++;
        }
        if(res!=INT_MAX)
        {
            return s.substr(start,res);
        }
        return "";
        
    }
};
