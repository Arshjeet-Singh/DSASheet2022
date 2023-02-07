class Solution {
public:
int solve(vector<int>& arr, map<pair<int,int>,int> &mp,int l,int r)
{
    if(l==r)
    {
        return 0;
    }
    int ans=INT_MAX;
    for(int i=l;i<r;i++)
    {
        ans=min(ans,mp[{l,i}]*mp[{i+1,r}]+ solve(arr,mp,l,i)+ solve(arr,mp,i+1,r));
    }
    return ans;
}
int solvem(vector<int>& arr, map<pair<int,int>,int> &mp,int l,int r,vector<vector<int>> &dp)
{
    if(l==r)
    {
        return 0;
    }
    int ans=INT_MAX;
    if(dp[l][r]!=-1)
    {
        return dp[l][r];
    }
    for(int i=l;i<r;i++)
    {
        ans=min(ans,mp[{l,i}]*mp[{i+1,r}]+ solvem(arr,mp,l,i,dp)+ solvem(arr,mp,i+1,r,dp));
    }
    return dp[l][r]=ans;
}
int solvet(vector<int>& arr,map<pair<int,int>,int> &mp)
{
    int n=arr.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int l=n-1;l>=0;l--)
    {
        for(int r=0;r<n;r++)
        {
            if(l==r)
            {
                dp[l][r]=0;
                continue;
            }
            int ans=1e9;
            for(int i=l;i<r;i++)
            {
                ans=min(ans,mp[{l,i}]*mp[{i+1,r}]+ dp[l][i]+ dp[i+1][r]);
            }
            dp[l][r]=ans;
        }
    }
    return dp[0][n-1];
}
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        map<pair<int,int>,int> mp;
        for(int i=0;i<n;i++)
        {
             mp[{i,i}]=arr[i];
            for(int j=i+1;j<n;j++)
            {
                int b=mp[{i,j-1}];
                mp[{i,j}]=max(arr[j],b);
            }
        }
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return solvem(arr,mp,0,n-1,dp);      
        return solvet(arr,mp);
    }

};

//before course
class Solution {
public:
    map<pair<int,int>,pair<int,int>> dp;
    pair<int,int> go(vector<int>& arr,int st,int en)
    {
        if(st==en)
        {
            return {arr[st],0};
        }
        if(dp.count({st,en}))
        {
            return dp[{st,en}];
        }
        int maxleaf=INT_MIN;
        int minsum=INT_MAX;
        for(int i=st;i<en;i++)
        {
            auto left=go(arr,st,i);
            auto right=go(arr,i+1,en);
            maxleaf=max(left.first,right.first);
            minsum=min(minsum,left.second+right.second+left.first*right.first);
            // minsum=min(minsum,)
            
        }
        return dp[{st,en}]={maxleaf,minsum};
       //  return dp[{st,en}];
    }
    int mctFromLeafValues(vector<int>& arr) {
        
        return go(arr,0,arr.size()-1).second;
    }
};
