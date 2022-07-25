class Solution {
 public:
    bool isNumber(string s) {
        bool digit=false,exp=false,dot=false;
        int countsign=0,n=s.length();
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if(isdigit(ch))
            {
                digit=true;
            }
            else if(ch=='+' ||ch=='-')
            {
                if(countsign==2)
                {
                    return false;
                }
                if(i>0 &&(s[i-1]!='e' && s[i-1]!='E'))
                {
                    return false;
                }
                if(i==s.length()-1)
                {
                    return false;
                }
                countsign++;
            }
            else if(ch=='e' || ch=='E')
            {
                if(exp || !digit ||(i==s.length()-1))
                {
                    return false;
                }
                // if(i+1<n && (s[i+1]!='+' || s[i+1]!='-'))
                // {
                //     return false;
                // }
                exp=true;
            }
            else if(ch=='.')
            {
                if(dot ||exp || (!digit && i==s.length()-1))
                {
                    return false;
                }
                dot=true;
            }
            else
            {
                return false;
            }
        }
        return true;
    } 
};
