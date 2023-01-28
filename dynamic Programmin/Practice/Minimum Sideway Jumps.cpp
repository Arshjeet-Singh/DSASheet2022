class Solution {
public:
int solve(vector<int>& obstacles,int currpos,int currlane)
{
    int n=obstacles.size();
    if(currpos==n)
    {
        return 0;
    }
    if(obstacles[currpos+1]!=currlane)
    {
        return solve(obstacles,currpos+1,currlane);
    }
    else
    {
        int ans=INT_MAX;
        for(int i=1;i<=3;i++)
        {
            if(currlane!=i && obstacles[currpos]!=i)
            {
                ans=min(ans,1+solve(obstacles,currpos,i));
            }
        }
         return ans;
    }
   
}
int solvem(vector<int>& obstacles,int currlane,int currpos,vector<vector<int>> &dp)
{
    int n=obstacles.size()-1;
    if(currpos==n)
    {
        return 0;
    }
    if(dp[currlane][currpos]!=-1)
    {
        return dp[currlane][currpos];
    }
    if(obstacles[currpos+1]!=currlane)
    {
        return solvem(obstacles,currlane,currpos+1,dp);
    }
    else
    {
        int ans=INT_MAX;
        for(int i=1;i<=3;i++)
        {
            if(currlane!=i && obstacles[currpos]!=i)
            {
                ans=min(ans,1+solvem(obstacles,i,currpos,dp));
            }
        }
         dp[currlane][currpos]=ans;
         return dp[currlane][currpos];
    } 
}
int solvet(vector<int>& obstacles)
{
    int n=obstacles.size()-1;
    // vector<vector<int>> dp(4,vector<int>(obstacles.size(),1e9));
    vector<int> curr(4,1e9);
    vector<int> next(4,1e9);      
    for(int i=0;i<=3;i++)
    {
        // dp[i][n]=0;
        next[i]=0;
    }
    for(int pos=n-1;pos>=0;pos--)
    {
        for(int lane=1;lane<=3;lane++)
        {
            if(obstacles[pos+1]!=lane)
            {
                // dp[lane][pos]=dp[lane][pos+1];
                curr[lane]=next[lane];
            }
            else
            {
                int ans=1e9;
                for(int i=1;i<=3;i++)
                {
                    if(lane!=i && obstacles[pos]!=i)
                    {
                        // ans=min(ans,1+dp[i][pos+1]);
                        ans=min(ans,1+next[i]);
                    }
                }
                // dp[lane][pos]=ans;
                curr[lane]=ans;
            }
                 
        }
         next=curr; 
    }
    // return min(dp[2][0],min(1+dp[1][0],1+dp[3][0]));
    return min(next[2],min(1+next[1],1+next[3]));
}
    int minSideJumps(vector<int>& obstacles) {
        // vector<vector<int>> dp(4,vector<int>(obstacles.size(),-1));          
        // return solvem(obstacles,2,0,dp);
        return solvet(obstacles);   
    }
};
