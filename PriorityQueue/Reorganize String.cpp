class Solution {
public:
    string reorganizeString(string s) {
        string  ans="";
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
        }
        priority_queue<pair<int,char>> q;
        for(auto x:m)
        {
            q.push({x.second,x.first});
        }
        
            auto block=q.top();
            q.pop();
            ans+=block.second;
            block.first--;
        while(q.size()>0)
        {
            auto temp=q.top();
            q.pop();
            ans+=temp.second;
            temp.first--;
            if(block.first>0)
            {
                q.push(block);
            }
            block=temp;
        }
        if(block.first>0)
        {
            return "";
        }
        return ans;
            // auto ele2=q.top();
            // q.pop();
            
    }
};
// not working code
//         stack<char> st;
//         ans+=s[0];
//         for(int i=1;i<s.length();i++)
//         {
//             int k=ans.length()-1;
//             if(!st.empty() && st.top()!=ans[k])
//             {
//                 ans+=st.top();
//                 st.pop();
//             }
//             else if(ans[k]==s[i])
//             {
//                 st.push(s[i]);
//             }
//             else if(ans[k]!=s[i])
//             {
//                 ans+=s[i];
//             }
//         }
        
//         while(!st.empty())
//         {
//             int j=ans.length()-1;
//             if(!st.empty() && st.top()!=ans[j])
//             {
//                 ans+=st.top();
//                 st.pop();
//                 // j++;
//             }
//             else if(st.top()==ans[j])
//             {
//                 return "";
//             }
//         }
//         return ans;
