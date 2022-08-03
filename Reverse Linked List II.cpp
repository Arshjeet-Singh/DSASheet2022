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
    ListNode *reverse(ListNode *head)
    {
        if(head==0 ||head->next==0)
        {
            return head;
        }
        ListNode *prev=0,*curr=head,*nextnode=0;
        while(curr!=0)
        {
            nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==0 || left==right)
        {
            return head;
        }         
         ListNode *curr=head,*prev;
            int l=1;
            while(l!=left && curr!=0)
            {
                prev=curr;
                curr=curr->next;
                l++;
            }
            int r=l;
          ListNode *start=curr;
            while(r!=right && curr!=0)
            {
                curr=curr->next;
                r++;
            }
        ListNode *res;
        if(curr!=0)
        {
            res=curr->next;
        }
        curr->next=0;
        ListNode *newhead=reverse(start);
        if(prev!=0)
        {
            prev->next=newhead;
        }
        curr=prev;
        while(curr->next!=0)
        {
            curr=curr->next;
        }
        curr->next=res;
        if(left==1)
        {
            return newhead;
        }
        else
        {
            return head;
        }
    } 
//         int pos1=1;
//         while(p1!=0)
//         {
//             if(pos1==left)
//             {
//                 n1=p1;
//                 // p1d=p1;
//                 break;
//             }
//             pos1++;
//             p1d=p1;
//             p1=p1->next;
//         }
//         ListNode *p2=0,*n2=0;
//         if(n1!=0)
//         {
//             p2=n1->next;
//         }
//         int pos2=pos1+1;
//         while(p2!=0)
//         {
//             if(pos2==right)
//             {
//                 n2=p2->next;
//                 break;
//             }
//             pos2++;
//             p2=p2->next;
//         }
//         //n1   --- p2
//         if(p1d!=0)
//         {
//              p1d->next=0;
//         }
//        if(p2!=0)
//        {
//          p2->next=0;    
//        }
//         ListNode *h1=reverse(n1);
//         // ListNode *temp1=h1;
//         // while(temp1!=0)
//         // {
//         //     cout<<temp1->val<<" ";
//         //     temp1=temp1->next;
//         // }
//         // cout<<endl;
//         if(p1d!=0)
//         {
//              p1d->next=h1;
//         }
//         else
//         {
//             p1->next=0;
//         }
//        if(n1!=0)
//        {
//          n1->next=n2;   
//        }      
//         return head;
};
