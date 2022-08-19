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
    //reverse function for iterative approach
    void reverse(ListNode *s,ListNode *e)
    {
        ListNode *curr=s,*prev=0,*nextnode=s->next;
        while(e!=prev)
        {
            // nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
            if(nextnode!=0)
            {
                nextnode=nextnode->next;
            }
        }
        // e=prev;
    }

    // void reverse(ListNode *s,ListNode *e)
    // {
    //     ListNode *curr=s,*prev=0,*nextnode=0;
    //     while(curr!=0 && e!=prev)
    //     {
    //         nextnode=curr->next;
    //         curr->next=prev;
    //         prev=curr;
    //         curr=nextnode;
    //     }
    //     e=prev;
    // }
    ListNode* reverseKGroup(ListNode* head, int k) {
        //without recursion approach
        if(head==0 || head->next==0 || k==1)
        {
            return head;
        }
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *beforestart=dummy;
        ListNode *end=head;
        int i=0;
        while(end!=0)
        {
            i++;
            if(i%k==0)
            {
                ListNode *start=beforestart->next;
                ListNode *temp=end->next;
                reverse(start,end);
                beforestart->next=end;
                start->next=temp;
                beforestart=start;
                end=temp;
            }
            else
            {
                end=end->next;
            }
            // i++;
        }
        return dummy->next;
        //using recursion
//         if(head==0 || head->next==0 ||k==1)
//         {
//             return head;
//         }
//         ListNode *s=head,*e=head;
//         int c=k-1;
//         while(c--)
//         {
            
//             e=e->next;
//             if(e==0)
//             {
//                 return head;
//             }
//         }
//           ListNode *nexthead=reverseKGroup(e->next,k);
//          reverse(s,e);
      
       
//         s->next=nexthead;
//         return e;
    }
    //does not deal with the case when we have to leave the last node
    //         if(head==0)
//         {
//             return head;
//         }
//         ListNode *curr=head;
//         int count=0;
//         ListNode *prev=0,*nextnode=0;
//         ListNode *temp=head;
//         while(curr!=0 && count<k)
//         {
//             nextnode=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=nextnode;
//             count++;
//         }
//         if(nextnode!=0)
//         {
//             head->next=reverseKGroup(nextnode,k);    
//         }
        
//         return prev;
};
