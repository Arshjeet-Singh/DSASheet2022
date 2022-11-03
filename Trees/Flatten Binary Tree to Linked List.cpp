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
    void conv(TreeNode*root,TreeNode *&head)
    {
        if(root==0)
        {
            return;
        }
        conv(root->right,head);
        root->right=head;
        if(head)
        {
            head->left=root;    
        }
        head=root;
        conv(root->left,head);
        // root->right=head;
        // head->right=root;
        
    }
    void flatten(TreeNode* root) {
        if(root==0)
        {
            return;
        }
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode *temp=st.top();
            st.pop();
            if(temp->right)
            {
                st.push(temp->right);
            }
            if(temp->left)
            {
                st.push(temp->left);
            }
            if(!st.empty())
            {
                temp->right=st.top();
            }
            temp->left=0;
        }
        // TreeNode *head=0;
        // conv(root,head);
        // TreeNode* temp=root;
        // while(temp!=0)
        // {
        //     temp->left=0;
        //     temp=temp->right;
        // }
        // root=head;
    }
};
