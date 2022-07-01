#include<bits/stdc++.h>
int ceilingInSortedArray(int n, int x, vector<int> &arr){
    int low=0,high=n-1;
    int res;
    if(arr[high]<x)
    {
        return -1;
    }
    if(arr[low]>=x)
    {
        return arr[low];
    }
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==x)
        {
            return arr[mid];
        }
        else if(arr[mid]<x)
        {
            low=mid+1;
        }
        else
        {
            res=mid;
            high=mid-1;
        }
    }
    return arr[res];
    // Write your code here.
}
