/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/
#include<unordered_map>
Node *removeDuplicates(Node *head)
{
    unordered_map<int,int> mp;
    Node *curr=head;
    mp[curr->data]=1;
    Node *prev=curr;
    curr=curr->next;
    while(curr!=0)
    {
        if(mp[curr->data]>0)
        {
            prev->next=curr->next;
            delete curr;
        }
        else
        {
            mp[curr->data]=1;
            prev=curr;
        }
        curr=prev->next;
    }
//     while(temp!=0)
//     {
//         mp[temp->data]++;
//         temp=temp->next;
//     }
//     temp=head;
//     Node *prev=temp;
//     while(temp!=0)
//     {
//         if(mp[temp->data]>0)
//         {
//             mp[temp->data]=0;
//             prev=temp;
//             temp=temp->next;
//         }
//         else
//         {
//             if(temp->next!=0)
//             {
//                 Node *nextnode=temp;
//                 prev->next=temp->next;
//                 delete nextnode;
//                 temp=prev->next;
//             }
//             else
//             {
//                 Node *nextnode=prev->next;
//                     prev->next=0;
//                 delete nextnode;
                
//             }
//         }
//     }
    return head;
    // Write your code here
}
