#include<bits/stdc++.h>
vector<int> patternSearch(string text, string pattern) {
    vector<int> v;
    int bc[256];
    int n=text.length();
    int m=pattern.length();
    memset(bc,-1,sizeof(bc));
    for(int i=0;i<m;i++)
    {
        bc[(int)pattern[i]]=i;
    }
    int j=m-1;
    int s=0;
    while(s<=(n-m))
    {
        j=m-1;
        while(j>=0 && pattern[j]==text[s+j])
        {
            j--;
        }
        if(j<0)
        {
            v.push_back(s);
            if(s+m<n)
            {
                s+=m-bc[text[s+m]];
            }
            else
            {
                s+=1;
            }
        }
        else
        {
            s+=max(1,j-bc[text[s+j]]);
        }
    }
    if(v.empty())
    {
        v.push_back(-1);
    }
    return v;
        
    // Write your code here.
}
