class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<int> s1,s2;
        vector<int> nexts(n);
        vector<int> prevs(n);
        for(int i=0;i<n;i++)
        {
            nexts[i]=n-i-1;
            prevs[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            while(!s1.empty() && arr[s1.top()]>arr[i])
            {
                
                nexts[s1.top()]=i-s1.top()-1;
                s1.pop();
            }
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!s2.empty() && arr[s2.top()]>=arr[i])
            {
                prevs[s2.top()]=s2.top()-i-1;
                s2.pop();
            }
            s2.push(i);
        }
        long long ans=0;
        long long mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            ans+=(arr[i]%mod)*(((prevs[i]+1)%mod)*((nexts[i]+1)%mod))%mod;
            ans%=mod;
        }
        return ans;
}
};
