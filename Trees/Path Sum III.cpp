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
    int cnt=0;
    void helper(TreeNode* root, int targetSum,long sum,unordered_map<long,int> &mp)
    {
        if(root==0)
        {
            return;
        }
        sum+=root->val;
        if(sum==targetSum)
        {
            cnt++;
        }
        if(mp.find(sum-targetSum)!=mp.end())
        {
            cnt+=mp[sum-targetSum];
        }
        mp[sum]++;
        helper(root->left,targetSum,sum,mp);
        helper(root->right,targetSum,sum,mp);
        mp[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        // int cnt=0;
        unordered_map<long,int> mp;
        helper(root,targetSum,0,mp);
        return cnt;
    }
};
