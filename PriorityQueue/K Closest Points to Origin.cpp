class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<long long,vector<int>>> pq;
        // unordered_map<vector<int>,bool> mp;
        for(int i=0;i<points.size();i++)
        {
            pq.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],points[i]});
            // mp[points[i]]=1;
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
