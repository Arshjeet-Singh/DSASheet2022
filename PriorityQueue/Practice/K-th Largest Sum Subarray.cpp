#include<queue>
// #include<bits/stdc++.h>
// #include<priority_queue>
int getKthLargest(vector<int> &arr, int k)
{
//     int maxi=arr[0],cs=0;
      priority_queue<int,vector<int>,greater<int>> pq;
//     pq.push(maxi);
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=arr[j];
            pq.push(sum);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
    }
    return pq.top();
//     for(int i=0;i<arr.size();i++)
//     {
//         cs+=arr[i];
//         if(cs>maxi)
//         {
//             maxi=cs;
//              pq.push(maxi);
//         }
//         if(pq.size()>k)
//         {
//             pq.pop();
//         }
//         if(cs<0)
//         {
//             cs=0;
//         }
//     }
//     return pq.top();
	//	Write your code here.
}
