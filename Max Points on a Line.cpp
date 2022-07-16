class Solution {
public:
    
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        // if(n==1 ||n==2)
        // {
        //     return n;
        // }
        unordered_map<string,int> mp;
        int localmax=0;
        for(int i=0;i<n;i++)
        {
            int dup=1;
            for(int j=i+1;j<n;j++)
            {
                if(points[j][0]==points[i][0] && points[j][1]==points[i][1])
                {
                    dup++;  
                }
                else
                {
                     int x=points[j][0]-points[i][0];
                    int y=points[j][1]-points[i][1];
                    int gcd=__gcd(x,y);
                    x/=gcd;
                    y/=gcd;
                    mp[to_string(x)+' '+to_string(y)]++;
                }
                // else if(points[j][0]-points[i][0]==0)
                // {
                //     slope=INT_MAX;
                // }
                // else
                // {
                //         slope=double(points[j][1]-points[i][1])/double(points[j][0]-points[i][0]);    
                // }
                // mp[slope]++;
            }
            localmax=max(localmax,dup);
            for(auto it=mp.begin();it!=mp.end();it++)
            {
                localmax=max(localmax,it->second+dup);
            }
            mp.clear();
            // localmax+=dup;
            // ans=max(localmax,ans);
            // mp.clear();
        }
        return localmax;
    } 
};
