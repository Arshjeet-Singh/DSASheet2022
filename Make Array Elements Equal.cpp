#include<bits/stdc++.h>
int cost(vector<int> &arr, int n,int x)
{
    int cost=0;
    for(int i=0;i<n;i++)
    {
        cost+=abs(arr[i]-x);
    }
    return cost;
}
int findMinimumCost(vector<int> &arr, int n)
{
    int minn=INT_MAX;
    int maxn=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<minn)
        {
            minn=arr[i];
        }
        if(arr[i]>maxn)
        {
            maxn=arr[i];
        }
    }
    while((maxn-minn)>2)
    {
        int mid1=minn+(maxn-minn)/3;
        int mid2=maxn+(minn-maxn)/3;
        int cost1=cost(arr,n,mid1);
        int cost2=cost(arr,n,mid2);
        if(cost1<cost2)
        {
            maxn=mid2;
        }
        else
        {
            minn=mid1;
        }
        
    }
    return cost(arr,n,(minn+maxn)/2);
    // Write your code here
}
