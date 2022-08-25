class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> q;
        int n=heights.size();
        int i=0;
        for(i=0;i<n-1;i++)
        {
            if(heights[i+1]<=heights[i])
            {
                continue;
            }
            int diff=heights[i+1]-heights[i];
            if(bricks>=diff)
            {
                bricks-=diff;
                q.push(diff);
            }
            else if(ladders>0)
            {
                if(!q.empty() && diff<q.top())
                {
                  int x=q.top();
                    bricks+=x;
                    bricks-=diff;
                    q.pop();
                    q.push(diff);
                
                }
                ladders--;
            }
            else
            {
                break;    
            }
        }
        return i;
    }
};
