/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    void createmap(Node *root)
    {
        if(root==0)
        {
            return;
        }
        queue<Node*> q;
        q.push(root);
        // mp[root]=0;
        
        while(!q.empty())
        {
            int si=q.size();
            for(int i=0;i<si;i++)
            {
                Node *temp=q.front();
                q.pop();
                if(temp->left)
                {
                    q.push(temp->left);
                    // mp[temp->left]=temp;
                    // temp=temp->left;
                }
                if(temp->right)
                {
                    q.push(temp->right);
                    // mp[temp->right]=temp;
                    // temp=temp->right;
                }
                if(i==si-1)
                {
                    temp->next=0;
                }
                else
                {
                    temp->next=q.front();
                }
            }
           
        }
    }
    // void traverse(Node *root,unordered_map<Node*,Node*> &mp)
    // {
    //     if(root==0)
    //     {
    //         return;
    //     }
    //     if(mp[root])
    //     {
    //         root->next=mp[root]->right;
    //     }
    //     else
    //     {
    //         root->next=0;
    //     }
    //     traverse(root->left,mp);
    //     traverse(root->right,mp);
    // }
    Node* connect(Node* root) {
        // unordered_map<Node *,Node*> mp;
        createmap(root);
        // traverse(root,mp);
        return root;
    }
};
