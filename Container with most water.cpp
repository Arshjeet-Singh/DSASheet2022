class Solution {
public:
    int maxArea(vector<int>& height) {
        int w=0;
        int i=0,j=height.size()-1;
        while(i<j)
        {
            int h=min(height[i],height[j]);
            w=max(w,(j-i)*h);
            while(height[i]<=h && i<j)
            {
                i++;
            }
            while(height[j]<=h && i<j)
            {
                j--;
            }
        }
        return w;
        // int n=height.size();
        // int a[n-1],b[n-1];
        // memset(a,n,0);
        // memset(b,n,0);
        // for(int i=0;i<n-1;i++)
        // {
        //     a[i]=(n-1-i)*min(height[i],height[n-1]);
        // }
        // for(int i=n-2;i>0;i--)
        // {
        //     b[i]=(i)*min(height[i],height[0]);
        // }
        // int ans=INT_MIN;
        // for(int i=0;i<n-1;i++)
        // {
        //     ans=max(ans,max(a[i],b[i]));
        // }
        // return ans;
    }
};
