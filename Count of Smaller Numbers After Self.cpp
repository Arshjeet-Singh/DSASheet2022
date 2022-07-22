class Solution {
public:
    void merge(vector<int>& count,vector<pair<int,int>>& v,int left,int mid,int right)
    {
        // int n=v.size();
        vector<pair<int,int>> temp(right-left+1);
        int i=left;
        int j=mid+1;
        int k=0;
        while(i<=mid && j<=right)
        {
            if(v[i].first<=v[j].first)
            {
                temp[k++]=v[j++];
            }
            else
            {
                //main thing
                count[v[i].second]+=right-j+1;
                temp[k++]=v[i++];
            }
        }
        while(i<=mid)
        {
            temp[k++]=v[i++];
        }
        while(j<=right)
        {
            temp[k++]=v[j++];
        }
        for(int l=left;l<=right;l++)
        {
            v[l]=temp[l-left];
        }
    }
    void mergesort(vector<int>& count,vector<pair<int,int>>& v,int left,int right)
    {
        if(right<=left)
        {
            return;
        }
        int mid=left+(right-left)/2;
        mergesort(count,v,left,mid);
        mergesort(count,v,mid+1,right);
        merge(count,v,left,mid,right);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> v(n);
        vector<int> count(n,0);
        for(int i=0;i<n;i++)
        {
            v[i].first=nums[i];
            v[i].second=i;
        }
        mergesort(count,v,0,n-1);
        return count;
        // v[n-1]=0;
        // for(int i=n-2;i>=0;i--)
        // {
        //     if(nums[i]>nums[i+1])
        //     {
        //         v[i]=v[i+1]+1;
        //     }
        //     else
        //     {
        //         // int c=0;
        //         for(int j=i+1;j<n;j++)
        //         {
        //             if(nums[i]>nums[j])
        //             {
        //                 v[i]=v[j]+1; 
        //                 break;
        //             }
        //             else if(nums[i]==nums[j])
        //             {
        //                 v[i]=v[j];
        //                 break;
        //             }
        //         }
        //         // v[i]=c;
        //     }
        // }
        return count;
    }
};
