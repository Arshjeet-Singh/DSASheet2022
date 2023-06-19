class Solution {
public:
    int help1(int ind,string s,vector<int> &dp)
    {
        if(ind>=s.size())
        {
            return 1;
        }
        if(s[ind]=='0')
        {
            return 0;
        }
        if(ind==s.size()-1)
        {
            return 1;
        }
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        if(s[ind]=='1' ||(s[ind]=='2' && s[ind+1]>=48 && s[ind+1]<=54))
        {
            return dp[ind]=help1(ind+1,s,dp)+help1(ind+2,s,dp);
        }
        return dp[ind]=help1(ind+1,s,dp);
    }
    int help(int ind,string s)
    {
        if(ind>=s.size())
        {
            return 1;
        }
        if(s[ind]=='0')
        {
            return 0;
        }
        if(ind==s.size()-1)
        {
            return 1;
        }
        if(s[ind]=='1' ||(s[ind]=='2' && s[ind+1]>=48 && s[ind+1]<=54))
        {
            return help(ind+1,s)+help(ind+2,s);
        }
        return help(ind+1,s);
        // if(ind>=s.size())
        // {
        //     return 0;
        // }
        // if(s[ind]=='0')
        // {
        //     return 0;
        // }
        // if(s.size()==1)
        // {
        //     if(s[0]=='0')
        //     {
        //         return 0;
        //     }
        //     return s.size();
        // }
        // int a=0,b=0;
        // if(s[ind]!='0')
        // {
        //     a=1+help(ind+1,s);
        // }
        // string s1="";
        // s1+=s[ind];
        // s1+=s[ind+1];
        // if(s1>="10" && s1<="26")
        // {
        //     b=1+help(ind+2,s);
        // }
        // return a+b;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,-1);
        return help1(0,s,dp);
        
    }
};
