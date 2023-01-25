#include <bits/stdc++.h> 
void selectionSort(vector<int>& arr, int n)
{   
    for(int i=0;i<n-1;i++)
    {
        int minind=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minind])
            {
                minind=j;
            }
        }
        swap(arr[i],arr[minind]);
    }
    // Write your code here.
}
