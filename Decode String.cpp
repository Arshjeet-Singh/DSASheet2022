class Solution {
public:
    string decodeString(string s) {
        string res="";
        stack<string> ss;
        stack<int> is;
        int i=0;
        int num=0;
        // string h;
        while(i<s.length())
        {
            if(isdigit(s[i]))
            {
                    num=num*10+(s[i]-'0');
            }
            else if(s[i]=='[')
            {
                ss.push(res);
                is.push(num);
                num=0;
                res="";
            }
            else if(s[i]==']')
            {
                string h=ss.top();
                ss.pop();
                int n=is.top();
                is.pop();
                for(int j=1;j<=n;j++)
                {
                    h+=res;
                }
                res=h;
            }
            else
            {
                res+=s[i];
            }
            i++;
        }
        return res;
    //     for(int i=0;i<s.length();i++)
    //     {
    //         if(s[i]!='[' && s[i]!=']')
    //         {
    //             st.push(s[i]);
    //         }
    //     }
    //     while(!st.empty())
    //     {
    //         int f=0;
    //         string h="";
    //         char t=st.top();
    //         st.pop();
    //         if(t>=49 && t<=57)
    //         {
    //             f=1;
    //             for(int i=0;i<(t-48);i++)
    //             {
    //                 h=h+h;
    //             }
    //         }
    //         else
    //         {
    //             h+=t;
    //         }
    //         if(f)
    //         {
    //             reverse(h.begin(),h.end());
    //             f=0;
    //             ans+=h;
    //         }
    //     }
    //     reverse(ans.begin(),ans.end());
    //     return ans;
    }
};
