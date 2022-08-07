/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node *flattenh(Node *head)
    {
        Node *curr=head;
        Node *tail=head;
        while(curr!=0)
        {
            Node *nextnode=curr->next,*childnode=curr->child;
            if(childnode!=0)
            {
                tail=flattenh(childnode);
                tail->next=nextnode;
                if(nextnode!=0)
                {
                    nextnode->prev=tail;
                }
                curr->next=childnode;
                childnode->prev=curr;
                curr->child=0;
                curr=tail;
            }
            else
            {
                curr=nextnode;
                if(curr!=0)
                {
                    tail=curr;
                }
            }
        }
        return tail;
    }
    Node* flatten(Node* head) {
        if(head)
        {
            flattenh(head);
        }
        return head;
    }
};
