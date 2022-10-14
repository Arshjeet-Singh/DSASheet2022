class Solution {
public:
    int parent(vector<int>p,int n)
    {
        if(p[n]==n)
        {
            return n;
        }
        return parent(p,p[n]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> v;
        vector<int> p(1001,0);
        for(int i=0;i<1001;i++)
        {
            p[i]=i;
        }
        
        for(auto itr:edges)
        {
            int n1=itr[0],n2=itr[1];
            int p1=parent(p,n1),p2=parent(p,n2);
            if(p1==p2)
            {
                v=itr;    
            }
            else
            {
                p[p1]=p2;
            }
        }
        return v;
    }
};
