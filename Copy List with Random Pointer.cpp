/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertattail(Node *&head,Node *&tail,int d)
    {
        Node *newnode=new Node(d);
        if(head==0 && tail==0)
        {
            head=tail=newnode;
            return;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
    }
    Node* copyRandomList(Node* head) {
        Node *anshead=0,*anstail=0;
        Node *temp=head;
        while(temp!=0)
        {
            int d=temp->val;
            insertattail(anshead,anstail,d);
            temp=temp->next;
        }
        temp=head;
        Node *original=head,*clone=anshead,*temp1;
        while(original!=0 && clone!=0)
        {
            temp=original->next;
            original->next=clone;
            original=temp;
            temp1=clone->next;
            clone->next=original;
            clone=temp1;
        }
        original=head;
        clone=anshead;
        temp=head;
        // step 3 random pointer copy
         while(temp!=0 && temp->next!=0)
        {
                 if(temp->next!=0)
                 {
                     if(temp->random!=0)
                     {
                        temp->next->random=temp->random->next; 
                     }
                     else
                     {
                         temp->next->random=temp->random;
                     }
                                
                 }
            
             temp=temp->next->next;
        }
        //revert the change sdone in step 2
        original=head;
        clone=anshead;
        while(original!=0 && clone!=0)
        {
            original->next=clone->next;
            original=original->next;
            if(original!=0)
            {
                clone->next=original->next;
            }
                
            clone=clone->next;
           
        }
//         temp1=clone;
//         while(temp1!=0)
//         {
//             if(temp1->next!=0)
//             {
//              temp1->next=temp1->next->next;   
//             }
//             else
//             {
//                 temp1->next=0;
//             }
            
//             temp1=temp1->next;
//         }
        return anshead;
    }
};
