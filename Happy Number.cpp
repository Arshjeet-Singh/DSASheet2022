class Solution {
    private:
    int sqsum(int num)
    {
         int ans=0;
            while(num>0)
            {
                int r=num%10;
                ans+=r*r;
                num/=10;
            }
        return ans;
    }
public:
    bool isHappy(int n) {
        int slow=n,fast=n;
        do{
            slow=sqsum(slow);
            fast=sqsum(fast);
            fast=sqsum(fast);
        }while(slow!=fast);
        if(slow==1)
        {
            return true;
        }
        else
        {
            return false;
        }
        // if(n==1)
        // {
        //     return true;
        // }
        // int num=n,count=0;
        // while(num!=1 && count!=100)
        // {
        //     int ans=0;
        //     while(num>0)
        //     {
        //         int r=num%10;
        //         ans+=r*r;
        //         num/=10;
        //     }
        //     num=ans;
        //     if(num==1)
        //     {
        //         return true;
        //     }
        //     count++;
        // }
        // return false;
    }
};
