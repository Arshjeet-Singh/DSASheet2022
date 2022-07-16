class Solution {
public:
    bool isPalindrome(int x) 
    {
         if(x<0 && x!=0)
        {
            return false;
        }
          int t=x,i=0;
        long reverse=0;
        while(t>0)
        {
            int r=t%10;
            reverse=reverse*10+r;
            t/=10;
        }
        if(reverse==x)
        {
            return true;
        }
        else
        {
            return false;
        }
        // if(x<0 && x!=0)
        // {
        //     return false;
        // }
        // int t=x,i=0;
        // int a[100];
        // while(t>0)
        // {
        //     a[i]=t%10;
        //     i++;
        //     t=t/10;
        // }
        // for(int j=0;j<i;j++)
        // {
        //     if(a[j]==a[i-j-1])
        //     {
        //         continue;
        //     }
        //     else
        //     {
        //         return false;
        //         break;
        //     }
        // }
        // return true;
    }
};
