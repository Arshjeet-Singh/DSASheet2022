class Solution {
public:
    int bs(int x)
    {
        int s=0;
        int e=x;
        long long int sq=0;
        long long int ans=0;
        while(s<=e)
        {
            long long int mid=s+(e-s)/2;
            sq=mid*mid;
            if(sq==x)
            {
                return mid;
            }
            else if(sq<x)
            {
                ans=mid;
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return ans;
    }
    int mySqrt(int x) {
        return bs(x);
    }
};
