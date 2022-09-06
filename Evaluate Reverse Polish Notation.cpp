class Solution {
public:
    bool checkop(char ch)
    {
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
        {
            return true;
        }
        return false;
    }
    int convert(string s)
    {
        int ans=0;
        // cout<<s<<endl;
        for(int i=0;i<s.length();i++)
        {
            int digi=s[i]-'0';
            ans=ans*10+digi;
            // cout<<digi<<endl;
        }
        cout<<ans<<endl;
        return ans;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i<tokens.size();i++)
        {
            string s1=tokens[i];
            if(!checkop(s1[0]))
            {
                int a=convert(s1);
                s.push(a);
            }
            else
            {
                int a,b;
                if(!s.empty())
                {
                    a=s.top();
                    s.pop();
                }
                if(!s.empty())
                {
                    b=s.top();
                    s.pop();
                }
                if(s1[0]=='+')
                {
                    s.push(b+a);
                }
                else if(s1[0]=='-')
                {
                    s.push(b-a);
                }
                else if(s1[0]=='*')
                {
                    s.push(b*a);
                }
                else 
                {
                    s.push(b/a);
                }
            }
        }
        return s.top();
    }
};
