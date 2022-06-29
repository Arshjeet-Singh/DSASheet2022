class Solution {
public:
    int calculate(string s) {
        if(s.length()==0)
        {
            return 0;
        }
        int currentnum=0;
        int ans=0;
        stack<int> st; 
        char operation='+';
       for(int i=0;i<s.length();i++)
       {
           char current=s[i];
           if(isdigit(current))
           {
               currentnum=currentnum*10+(current-'0');
           }
           if(!isdigit(current) && !iswspace(current) || i==s.length()-1)
           {
               if(operation=='-')
               {
                   st.push(-currentnum);
               }
               else if(operation=='+')
               {
                   st.push(currentnum);
               }
               else if(operation=='*')
               {
                   int h=st.top();
                   st.pop();
                   st.push(currentnum*h);
               }
               else if(operation=='/')
               {
                    int h=st.top();
                   st.pop();
                   st.push(h/currentnum);
               }
                operation=current;
               currentnum=0;
           }
       }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
