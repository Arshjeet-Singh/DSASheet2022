class Solution {
public:
    void solve(int op,int close,string s,vector<string>& v)
    {
        if(op==0 && close==0)
        {
            v.push_back(s);
            return;
        }
        if(op!=0)
        {
            string s1=s;
            s1+='(';
            solve(op-1,close,s1,v);
        }
        if(close>op)
        {
            string s2=s;
            s2+=')';
            solve(op,close-1,s2,v);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s="";
        int op=n;
        int close=n;
        solve(op,close,s,v);
        return v;
    }
}; 
