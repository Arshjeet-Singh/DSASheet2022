class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int left = 0;
        for(int right =1; right< nums.size(); right++){
           if(nums[left] != nums[right])
           {
                left++;
           }
              
               nums[left] = nums[right];
           }
    return left+1;
        //using o(n) space
//         unordered_map<int,int> m;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(m[nums[i]]==0)
//             {
//                 m[nums[i]]=1;
//             }
//             else
//             {
//                 m[nums[i]]++;
//             }
//         }
//         int k=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(m[nums[i]]==1)
//             {
//                 nums[k]=nums[i];
//                 k++;
                
//             }
//             else if(m[nums[i]]>1)
//             {
//                 nums[k]=nums[i];
//                 k++;
//                 m[nums[i]]=0;
//             }
//         }
//         return k;
    }
};
