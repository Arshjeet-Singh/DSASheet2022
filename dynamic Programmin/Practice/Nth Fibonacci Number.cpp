#include<bits/stdc++.h>
using namespace std;
int fibo(int n,vector<int> &dp)
{
    if(n<=1)
    {
        return n;
        
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    //space optimise
    int prev1=1,prev2=0;
    int curr;
    if(n==0)
    {
        cout<<prev2<<endl;
    }
    for(int i=2;i<=n;i++)
    {
        curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    cout<<prev1<<endl;
    //tabulatin
//     dp[0]=0;
//     dp[1]=1;
//     for(int i=2;i<=n;i++)
//     {
//         dp[i]=dp[i-1]+dp[i-2];
//     }
//     cout<<dp[n]<<endl;
    //recur +memo
//     cout<<fibo(n,dp)<<endl;
        /*
        *  Write your code here. 
         *  Read input as specified in the question.
         *  Print output as specified in the question.
        */
}
