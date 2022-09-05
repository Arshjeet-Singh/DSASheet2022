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
class BSTIterator {
    private:
    stack<TreeNode *>s;
    void helper(TreeNode *a)
    {
        while(a!=0)
        {
            s.push(a);
            a=a->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
            helper(root);
    }
    
    int next() {
        TreeNode *a=s.top();
        s.pop();
        if(a->right!=0)
        {
            helper(a->right);
        }
        return a->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
