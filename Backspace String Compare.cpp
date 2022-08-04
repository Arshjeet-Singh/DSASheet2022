class Solution {
public:
    bool backspaceCompare(string s, string t) {
        //o(1) space soln
        int i=s.length()-1,j=t.length()-1,skips=0,skipt=0;
        while(i>=0 || j>=0)
        {
            while(i>=0)
            {
                if(s[i]=='#')
                {
                    skips++;
                    i--;
                }
                else if(skips>0)
                {
                    skips--; i--;
                }
                else
                {
                    break;
                }
            }
            while(j>=0)
            {
                if(t[j]=='#')
                {
                    skipt++;
                    j--;
                }
                else if(skipt>0)
                {
                    skipt--; j--;
                }
                else
                {
                    break;
                }
            }
            if(i>=0 && j>=0 && s[i]!=t[j])
            {
                return false;
            }
            if((i>=0)!=(j>=0))
            {
                return false;
            }
            i--; j--;
        }
        return true;
        //o(n) space soln
        // stack<char> st1,st2;
        // string s1,s2;
        // for(int i=0;i<s.length();i++)
        // {
        //     if(!st1.empty() && s[i]=='#')
        //     {
        //         st1.pop();
        //     }
        //     else if(s[i]=='#')
        //     {
        //         continue;
        //     }
        //     else
        //     {
        //         st1.push(s[i]);
        //     }
        // }
        // while(!st1.empty())
        // {
        //     s1+=st1.top();
        //     st1.pop();
        // }
        // for(int i=0;i<t.length();i++)
        // {
        //     if(!st2.empty() && t[i]=='#')
        //     {
        //         st2.pop();
        //     }
        //     else if(t[i]=='#')
        //     {
        //         continue;
        //     }
        //     else
        //     {
        //         st2.push(t[i]);
        //     }
        // }
        // while(!st2.empty())
        // {
        //     s2+=st2.top();
        //     st2.pop();
        // }
        // if(s1==s2)
        // {
        //     return true;
        // }
        // else
        // {
        //     return false;
        // }
    }
};
