#include <bits/stdc++.h> 
void heapify(vector<int> &arr,int n,int i)
{
    int li=2*i+1;
    int ri=2*i+2;
    int smallest=i;
        if(li<n && arr[li]<arr[smallest])
        {
            smallest=li;
        }
        if(ri<n && arr[ri]<arr[smallest])
        {
            smallest=ri;
        }
        if(smallest!=i)
        {
            swap(arr[smallest],arr[i]);
            heapify(arr,n,smallest);
        }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr,n,i);
    }
    return arr;
    // Write your code here
}
