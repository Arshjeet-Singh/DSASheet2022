class Solution {
    private:
    bool check(int a[],int b[])
    {
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
            {
                return 0;
            }
        }
        return 1;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int a[26]={0};
        int m=s1.length();
        for(int i=0;i<m;i++)
        {
            int ind=s1[i]-'a';
            a[ind]++;
        }
        int i=0;
        int n=s2.length();
        int b[26]={0};
        while(i<m && i<n)
        {
            int ind=s2[i]-'a';
            b[ind]++;
            i++;
        }
        if(check(a,b))
        {
            return 1;
        }
        while(i<n)
        {
            // if()
            int ind=s2[i]-'a';
            b[ind]++;
            ind=s2[i-m]-'a';
            b[ind]--;
            i++;

            if(check(a,b))
            {
                return 1;
            }
            
        }
        return 0;
    }
};
