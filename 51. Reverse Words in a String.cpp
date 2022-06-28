class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int i=0;
        while(i<s.length())
        {
            if(s[i]==' ')
            {
                i++;
                continue;
            }
            string temp="";
            while(s[i]!=' ' && i<s.length())
            {
                temp+=s[i];
                i++;
            }
            st.push(temp);
            i++;
        }
        string ans="";
        string s1;
        while(!st.empty())
        {
            s1=st.top();
            st.pop();
            if(st.empty())
            {
                ans+=s1;
                break;
            }
            ans+=s1+' ';
        }
        return ans;
        
    }
};
