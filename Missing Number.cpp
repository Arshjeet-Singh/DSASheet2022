class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int cs=(n*(n+1))/2;
        int os=0;
        for(int  i=0;i<n;i++)
        {
            os+=nums[i];
        }
        return abs(cs-os);
    }
};
//can be done using xor
// binary search if the array is sorted
