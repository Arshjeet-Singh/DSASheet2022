class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total=0;
        int l=0,r=cardPoints.size()-k;
         int cws=0;
        for(int i=r;i<cardPoints.size();i++)
        {
            cws+=cardPoints[i];
        }
        total=cws;
        while(r<cardPoints.size())
        {
            cws=cws-cardPoints[r]+cardPoints[l];
            total=max(total,cws);
            r++;
            l++;
        }
        return total;
//         for(int i=0;i<cardPoints.size();i++)
//         {
//             total+=cardPoints[i];
//         }
       
//         int j=0;
//         for(int i=cardPoints.size()-k;i<cardPoints.size();i++)
//         {
//             if(j==0)
//             {
//               ans=max(ans,total-cws);   
//             }
//             else
//             {
//                   ans=max(ans,total-cws-cardPoints[j++]+cardPoints[i]);   
//             }
          
//         }
//         return ans;
    }
};
