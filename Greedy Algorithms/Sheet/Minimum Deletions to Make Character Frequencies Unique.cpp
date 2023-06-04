class Solution {
public:
    int minDeletions(string s) {
        int ans=0;
        map<char,int> mp;
        unordered_map<char,int> mp1;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            // if(mp[s[i]]>1)
            // {
            //     if(mp1.size()>=1 && mp1[s[i]]>0)
            //     {
            //         continue;
            //     }
            //     else if(mp1.size()>=1)
            //     {
            //         ans++;
            //     }
            //     else
            //     {
            //         mp1[s[i]]=1;
            //     }
            // }
        }
        for(auto it:mp)
        {
            cout<<it.first<<" "<<it.second<<endl;
            mp1[it.second]++;
            if(mp1[it.second]>1)
            {
                cout<<it.first<<endl;
                int ic=it.second;
                while(mp1[ic]>=1 && ic!=0)
                {
                    ic--;
                    ans++;
                    // ans+=it.second;
                }
                mp1[it.second]--;
                mp1[ic]=1;
            }      
            // ans+=ic-ie
            // if(mp.second)
        } 

        // for(int i=0;i<n;i++)
        // {
        //     mp[s[i]]++;
        // }
        return ans;
    }
};
