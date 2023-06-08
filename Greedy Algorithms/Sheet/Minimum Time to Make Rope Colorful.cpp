class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int ans=0;
        int prev=0;
        for(int i=1;i<n;i++)
        {
            int mini=INT_MAX;
            if(colors[prev]==colors[i])
            {
                if(neededTime[prev]<=neededTime[i])
                {
                    ans+=neededTime[prev];
                    prev=i;
                }
                else
                {
                    ans+=neededTime[i];

                }
                // mini=min(neededTime[i],neededTime[i+1]);
            }
            else
            {
                prev=i;
            }
        }
        return ans;
    }
};
