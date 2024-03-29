/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *helper(vector<int>& nums,int start,int end)
    {
        if(start>end)
        {
            return 0;
        }
        int mid=(start+end)/2;
        TreeNode *newnode=new TreeNode(nums[mid]);
        TreeNode *left=helper(nums,start,mid-1);
        TreeNode *right=helper(nums,mid+1,end);
        newnode->left=left;
        newnode->right=right;
        return newnode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return helper(nums,0,n-1);
    }
};
