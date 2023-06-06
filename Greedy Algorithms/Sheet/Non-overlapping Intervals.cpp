class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int prev=0;
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<intervals[prev][1])
            {
                ans++;
                if(intervals[i][1]<=intervals[prev][1])
                {
                    prev=i;
                }
                
            }
            else
            {
                prev=i;
            }
        }
        return ans;
    }
};
