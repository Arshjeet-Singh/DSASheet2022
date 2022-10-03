#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    stack<char>st;
    for(int i=0;i<s.length();i++)
    {
        int c=0;
        if(s[i]=='(' ||s[i]=='*' || s[i]=='+' ||s[i]=='-' ||s[i]=='/')
        {
            st.push(s[i]);
        }
        else
        {
            
           if(s[i]==')')
           {
               bool redun=true;
               while(!st.empty() && st.top()!='(')
               {
                   char top=st.top();
                   if(top=='+' || top=='-' || top=='*' || top=='/')
                   {
                       redun=false;
                   }
                   st.pop();
               }
               if(redun==true)
                {
                    return true;
                }
               st.pop();
           }
        }
    }
    return false;
    // Write your code here.
}
