class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            if(s.empty())
            {
                st.push(s[i]);
            }
            else if(!st.empty() && st.top()==s[i])
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            } 
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        // int n=s.size();
        // if(n==0 ||  n==1)
        // {
        //     return s;
        // }
        // if(s[0]==s[1])
        // {
        //     int ind=0;
        //     while(s[0]==s[ind] && ind<n)
        //     {
        //         ind++;
        //     }
        //     return s[0]+removeDuplicates(s.substr(ind));
        // }
        // return s[0]+removeDuplicates(s.substr(1));
//         int i=0;
//         int sl=0;
//         while(s.length()!=0 && i<s.length())
//         {
//             char ch=s[i];
//             int iind=i;
//             while(s[i]==ch && i<s.length())
//             {
//                 sl++;
//                 i++;
//             }
//             if(sl>1)
//             {
//                 sl=0;
//                 cout<<s[iind]<<" "<<s[iind+sl];
//                 s.erase(s.find(ch),sl);
//             }
//             // else
//             // {
//             //     i++;    
//             // }         
//         }
//         return s;
    }
};
