#include <bits/stdc++.h> 
int findMinimumCost(string str) {
    if(str.length()%2!=0)
    {
        return -1;
    }
    stack<char> st;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='{')
        {
            st.push(str[i]);
        }
        
        else
        {
            if(!st.empty() && st.top()=='{')
            {
                st.pop();
            }
            else
            {
                st.push(str[i]);
            }
        }
    }
    int a=0,b=0;
    while(!st.empty())
    {
        int ch=st.top();
        st.pop();
        if(ch=='{')
        {
            a++;
        }
        else
        {
            b++;
        }
    }
    return ((a+1)/2)+((b+1)/2);
                     // Write your code here
}
