class Solution {
public:
bool check(vector<int> &base,vector<int> &newr)
{
    return newr[0]<=base[0] && newr[1]<=base[1] && newr[2]<=base[2];
}
 int so(int n,vector<vector<int>>& a)
    {
        vector<int> current(n+1,0);
        vector<int> next(n+1,0);
        for(int curr=n-1;curr>=0;curr--)
        {
            for(int prev=curr-1;prev>=-1;prev--)
            {
                int ex=next[prev+1];
                int in=0;
                if(prev==-1 ||  check(a[curr],a[prev]))
                {
                    in=a[curr][2]+next[curr+1];
                }
                current[prev+1]=max(in,ex);
            }
            next=current;
        }
        return next[-1+1];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        // for(auto &a: cuboids)
        // {
        //     sort(a.begin().a.end());
        // }
        for(int i=0;i<cuboids.size();i++)
        {
            sort(cuboids[i].begin(),cuboids[i].end());
        }
        sort(cuboids.begin(),cuboids.end());
        return so(cuboids.size(),cuboids);
    }
};
