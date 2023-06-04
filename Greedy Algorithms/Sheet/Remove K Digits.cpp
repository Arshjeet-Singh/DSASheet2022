class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        int n=num.size();
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && k>0 && s.top()>num[i])
            {
                s.pop();
                k--;
            }
            if(!s.empty() || num[i]!='0')
            {
                s.push(num[i]);
            }
        }
        string ans="";
        while(!s.empty() && k>0)
        {
            s.pop();
            k--;
        }
        if(s.empty())
        {
            return "0";
        }
        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
