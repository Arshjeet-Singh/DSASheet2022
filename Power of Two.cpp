class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
        {
            return false;
        }
        return (n&(n-1))==0;
        // int ans=1;
        // if(n==0)
        // {
        //     return false;
        // }
        // while(n%2==0)
        // {
        //     n/=2;
        // }
        // return n==1;
        // for(int i=0;i<=30;i++)
        // {
        //     if(ans==n)
        //     {
        //         return true;
        //     }
        //     if(ans>INT_MAX/2)
        //     {
        //         return false;
        //     }
        //     ans=ans*2;
        // }
        // return false;
    }
};
