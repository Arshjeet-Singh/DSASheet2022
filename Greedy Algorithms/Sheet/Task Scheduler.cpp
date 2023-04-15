class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0)
        {
            return tasks.size();
        }
        int ans=0;
        unordered_map<char,int> cnt;
        priority_queue<int> pq;
         unordered_map<char,int> prev;
        for(int i=0;i<tasks.size();i++)
        {
            cnt[tasks[i]]++;
        }
        for(auto c:cnt)
        {
            pq.push(c.second);
        }
        int res=0;
        while(!pq.empty())
        {
            vector<int> temp;
            int tempcnt=0;
            for(int i=0;i<n+1;i++)
            {
                if(!pq.empty())
                {
                    int t=pq.top();
                    pq.pop();
                    tempcnt++;
                    temp.push_back(t-1);
                }
              
            }
              for(auto itr:temp)
                {
                    if(itr)
                    {
                        pq.push(itr);
                    }
                }
            if(pq.empty())
            {
               res+=tempcnt; 
            }
            else
            {
                res+=n+1;
            }
        }
        return res;
    }
};
