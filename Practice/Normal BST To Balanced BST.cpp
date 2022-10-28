/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
void store(TreeNode<int>* root,vector<int> &v)
{
    if(root==0)
    {
        return;
    }
    store(root->left,v);
    v.push_back(root->data);
    store(root->right,v);
}
TreeNode<int>* getfromin(vector<int> &v,int s,int e)
{
    if(s>e)
    {
        return 0;
    }
    int mid=s+(e-s)/2;
    TreeNode<int>* root=new TreeNode<int>(v[mid]);
    root->left= getfromin(v,s,mid-1);
    root->right= getfromin(v,mid+1,e);
    return root;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    if(root==0)
    {
        return 0;
    }
    vector<int> v;
    store(root,v);
     return getfromin(v,0,v.size()-1);
    // Write your code here.
}
