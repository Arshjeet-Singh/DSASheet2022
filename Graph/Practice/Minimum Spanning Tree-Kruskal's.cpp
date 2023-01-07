#include<bits/stdc++.h>
bool cmp(vector<int> &a,vector<int> &b)
{
    return a[2] < b[2];
}
int findparent(vector<int> &p,int node)
{
    if(p[node]==node)
    {
        return node;
    }
    return p[node]=findparent(p,p[node]);
}
void unionset(vector<int> &p,vector<int> &r,int u,int v)
{
    u=findparent(p,u);
    v=findparent(p,v);
    if(r[u]<r[v])
    {
        p[u]=v;
    }
    else if(r[u]>r[v])
    {
        p[v]=u;
    }
    else
    {
        p[v]=u;
        r[u]++;
    }
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    sort(edges.begin(),edges.end(),cmp);
    int wt=0;
    vector<int> p(n);
    vector<int> r(n,0);
    for(int i=0;i<n;i++)
    {
        p[i]=i;
    }
    for(int i=0;i<edges.size();i++)
    {
        int u,v,w;
        u=edges[i][0];
        v=edges[i][1];
        w=edges[i][2];
        u=findparent(p,u);
        v=findparent(p,v);
        if(u!=v)
        {
            unionset(p,r,u,v);
            wt+=w;
        }
    }
    return wt;
    /*Don't write main().
    Don't read input, it is passed as function           argument.    
    No need to print anything.
    Taking input and printing output is handled automatically.
  */
}
