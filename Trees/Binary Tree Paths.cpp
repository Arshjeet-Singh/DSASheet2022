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
    void helper(TreeNode* root,string p,vector<string> &v)
    {
        p+=to_string(root->val);
        if(root->left==0 && root->right==0)
        {
            v.push_back(p);
            return;
        }
        if(root->left!=0)
        {
            helper(root->left,p+"->",v);    
        }
        if(root->right!=0)
        {
            helper(root->right,p+"->",v);    
        }
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        if(root==0)
        {
            return v;
        }
        helper(root,"",v);
        return v;
        // v.push_back()
//         s+=(string)root->val;
//         if(root->left==0)
//         {
//             v.push_back(s);
            
//         }        
    }
};
