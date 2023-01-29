class Solution {
public:
static bool cmp(vector<int> &a,vector<int>&b)
{
    if(a[0]==b[0])
    {
        return a[1]>b[1];
    }
    return a[0]<b[0];
}
    int maxEnvelopes(vector<vector<int>>& env) {
        int n=env.size();
        if(n==0)
        {
            return 0;
        }
        sort(env.begin(),env.end(),cmp);
        vector<int> ans;
        ans.push_back(env[0][1]);
        for(int i=1;i<n;i++)  
        {
            int ele=env[i][1];
            if(ele>ans.back())
            {
                ans.push_back(ele);
            }
            else
            {
                int ind=lower_bound(ans.begin(),ans.end(),ele)-ans.begin();
                ans[ind]=ele;
            }
        }
        return ans.size();
        // w.push_back(a[0][0]);
        // h.push_back(a[0][1]);
        // for(int i=1;i<n;i++)  
        // {
        //     if(a[i][1]>h.back())
        //     {
        //         // w.push_back(a[i][0]);
        //         h.push_back(a[i][1]);
        //     }
        //     else
        //     {
        //         // int ind=lower_bound(w.begin(),w.end(),a[i][0])-w.begin();
        //         int ind1=lower_bound(h.begin(),h.end(),a[i][1])-h.begin();
        //             h[ind1]=a[i][1];
                
        //     }
        // }
        // return h.size();
    }
};
