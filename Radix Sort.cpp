int getmax(vector<int>& arr,int n)
{
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>ans)
        {
            ans=arr[i];
        }
    }
    return ans;
}
void countsort(vector<int>& arr,int n,int pos)
{
    int count[10]={0};
    for(int i=0;i<n;i++)
    {
        ++count[(arr[i]/pos)%10];
    }
    for(int i=1;i<10;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    int b[n];
    for(int i=n-1;i>=0;i--)
    {
        b[--count[((arr[i]/pos)%10)]]=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=b[i];
    }
}
vector<int> radixSort(int n, vector<int>& arr) {
    int max=getmax(arr,n);
    for(int pos=1;max/pos>0;pos=pos*10)
    {
        countsort(arr,n,pos);
    }
    return arr;
    // Write your code here.
}
