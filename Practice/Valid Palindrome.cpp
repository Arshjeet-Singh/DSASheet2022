class Solution {
    private:
    bool ischar(char ch)
    {
        if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9'))
        {
            return true;
        }
        return false;
    }
    char lower(char ch)
    {
        if((ch>='a' && ch<='z')||(ch>='0' && ch<='9'))
        {
            return ch;
        }
        return ch-'A'+'a';
    }
    bool check(string s)
    {
        int st=0;
        int e=s.length()-1;
        while(st<e)
        {
            if(s[st]!=s[e])
            {
                return false;
            }
            st++;
            e--;
        }
        return true;
    }
public:
    bool isPalindrome(string s) {
        string temp="";
        int n=s.length();
        for(int i=n-1;i>=0;i--)
        {
            if(ischar(s[i]))
            {
                temp.push_back(lower(s[i]));
            }
        }
        return check(temp);
    }
};
