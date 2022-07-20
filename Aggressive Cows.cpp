bool possible(vector<int> &stalls, int k,int mindis)
{
    int lastpos=stalls[0];
    int dis=0,cow=1;
    for(int i=0;i<stalls.size();i++)
    {
        dis=stalls[i]-lastpos;
        if(dis>=mindis)
        {
            cow++;
            if(cow==k)
            {
                return true;
            }
            lastpos=stalls[i];
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int s=0;
    int maxi=-1;
    for(int i=0;i<stalls.size();i++)
    {
        maxi=max(maxi,stalls[i]);
    }
    int e=maxi;
    int ans=-1;
    while(s<=e)
    {
        int m=s+(e-s)/2;
        if(possible(stalls,k,m))
        {
            ans=m;
            s=m+1;
        }
        else
        {
            e=m-1;
        }
    }
    return ans;
    //    Write your code here.
}
