class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minh;
        // priority_queue<int, vector<int>, greater<int> > gquiz;
        int n=arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;            
        }
        for(auto it:mp)
        {
                minh.push({it.second,it.first});
            if(minh.size()>k)
            {
                minh.pop();
            }
        }
        vector<int> v;
        while(!minh.empty())
        {
            v.push_back(minh.top().second);
            minh.pop();
        }
        return v;
    }
};
