//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        int bal=0;
        int deficit=0;
        int start=0;
        for(int i=0;i<n;i++)
        {
            bal+=p[i].petrol-p[i].distance;
            if(bal<0)
            {
                start=i+1;
                deficit+=bal;
                bal=0;
            }
        }
        if(deficit+bal>=0)
        {
            return start;
        }
        else
        {
            return -1;
        }
        
        
        
        
        
        
        
        
        // int si=0;
        // queue<int> q;
        // for(int i=0;i<n;i++)
        // {
        //     if(p[i].petrol>=p[i].distance)
        //     {
        //         q.push(i);
        //         // cout<<i<<endl;
        //         // cout<<si<<endl;
        //     }
        // }
        // while(!q.empty())
        // {
        //     int a=q.front();
        //     q.pop();
        //     int tp=0;
        //     int count=0;
        //      tp+=p[(a+count)%n].petrol;
        //       tp-=p[(a+count)%n].distance;
        //       count++;
        //     while((a+count)%n!=a && tp>0)
        //     {
        //         tp+=p[(a+count)%n].petrol;
        //         // cout<<tp<<endl;
        //         tp-=p[(a+count)%n].distance;
        //         // cout<<tp<<endl;
        //         if(tp<0)
        //         {
        //             break;
        //         }
        //         count++;
        //     }
        //     if(count==n)
        //     {
        //         return a;
        //     }
        //     // if(tp<0)
        //     // {
        //     //     return false;
        //     // }
        // }
        
        
       //Your code here
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends
