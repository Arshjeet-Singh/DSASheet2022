/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *middle(ListNode *head)
    {
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast!=0 && fast->next!=0)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *curr=head,*prev=0,*nextn=0;
        while(curr!=0)
        {
            nextn=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextn;
        }
        return prev;
    }
    int len(ListNode *head)
    {
        ListNode *temp=head;
        int c=0;
        while(temp!=0)
        {
            c++;
            temp=temp->next;
        }
        return c;
    }
    void reorderList(ListNode* head) {
        ListNode *mid=middle(head);
        ListNode *second=mid->next;
        mid->next=0;
        second=reverse(second);
        ListNode *first=head;
        while(second!=0)
        {
            ListNode *temp1=first->next;
            ListNode *temp2=second->next;
            first->next=second;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }
        //n^2 soln
//        if(head==0 || head->next==0)
//        {
//            return;
//        }
//         ListNode *curr=head,*prev=0;
//         int i=0,l=len(head);
//         if(l%2==0)
//         {
//              ListNode *t1=head,*n1=head->next;
//             while(i<l/2 -1 && t1!=0)
//             {
//                 curr=head;
//                 while(curr->next!=0)
//                 {
//                     // cout
//                     prev=curr;
//                     curr=curr->next;
//                 }
// //                 if(curr!=n1)
// //                 {
                    
// //                 }
//                 prev->next=0;
//                     //n1=t1->next;
//                     t1->next=curr;
//                     curr->next=n1;
//                 t1=n1;
//                 if(n1!=0)
//                 {
//                     n1=n1->next;
//                 }
//                     // t1=n1;
//                   i++;  
//             } 
//         }
//         else
//         {
//              ListNode *t1=head,*n1=head->next;
//             while(i<l/2 )
//             {
//                 while(curr->next!=0)
//                 {
//                     prev=curr;
//                     curr=curr->next;
//                 }
               
//                 prev->next=0;
//                  t1->next=curr;
//                     curr->next=n1;
//                 t1=n1;
//                 if(n1!=0)
//                 {
//                     n1=n1->next;
//                 }
//                   i++;
//             } 
//         }
//         return;
    }
};
