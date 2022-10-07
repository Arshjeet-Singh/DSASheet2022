class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        int c=0;
        for(int i=0;i<s.length();i++)
        {
            if(!st.empty() && st.top().first==s[i])
            {
                c=st.top().second+1;
            }
            else
            {
                c=1;
            }
             st.push({s[i],c});
            if(c==k)
            {
                while(!st.empty() &&c!=0)
                {
                    st.pop();
                    c--;
                }
            }
        }
        string ans="";
        while(!st.empty())
        {
            auto a=st.top();
            st.pop();
            ans+=a.first;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
        
        
        //TLE METHOD
        /*int i=0;
        while(i<s.length())
        {
            string s2="";
            for(int j=0;j<k;j++)
            {
                s2+=s[i];
            }
            // cout<<s2<<endl;
            if(s.find(s2)<s.length())
            {
                while(s.length()!=0 && s.find(s2)<s.length())
                {
                    s.erase(s.find(s2),k);
                    i=0;
                }    
        
            }
                i++;
        }
        return s;*/
    }
};
