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
   void insertattail(ListNode *&head,ListNode *&tail,ListNode *curr)
   {
       if(head==0 && tail==0)
       {
           head=tail=curr;
       }
       else
       {
           tail->next=curr;
           tail=curr;
       }
   }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *first=l1,*second=l2;
        int carr=0;
         ListNode *anshead=0,*anstail=0;
        while(first!=0 || second!=0 ||carr!=0)
        {
            int val1=0,val2=0;
            if(first!=0)
            {
                val1=first->val;
            }
            if(second!=0)
            {
                val2=second->val;
            }
            int sum=val1+val2+carr;
            int digit=sum%10;
           
            ListNode *curr=new ListNode(digit);
            insertattail(anshead,anstail,curr);
            if(first!=0)
            {
                first=first->next;
            }
            if(second!=0)
            {
                second=second->next;
            }
            carr=sum/10;
        }
        return anshead;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // int len1=len(l1),len2=len(l2);
        // if(l1>=l2)
        // {
        //     return solve(l1,l2);
        // }
        // else
        // {
        //     return solve(l2,l1);
        // }
        // return 0;
//      int len(ListNode *h)
//     {
//         int c=0;
//         ListNode *t=h;
//         while(t!=0)
//         {
//             t=t->next;
//             c++;
//         }
//         return c;
//     }
//     ListNode *solve(ListNode* l1, ListNode* l2)
//     {
//         ListNode *t1 = l1,*t2 = l2;
//         while(t2!=0 )
//         {
//             int sum=t1->val+t2->val;
//             if(sum>=10)
//             {
//                 t1->val=sum%10;
//                 if(t1->next!=0)
//                 {
//                     t1->next->val+=sum/10;
//                     // if(t1->next->next==0)
//                     // {
//                     //     cout<<t1->next->val<<endl;
//                     // }
//                     // if(t1->next->next==0 && t1->next->val>=10)
//                     // {
//                     //     // t1=t1->next;
//                     //     t1->val=(t1->next->val)%10;
//                     //      ListNode *newnode=new ListNode(t1->next->val/10);
//                     //     t1->next=newnode;
//                     // }
//                 }
//                 else
//                 {
                    
//                     ListNode *newnode=new ListNode(sum/10);
//                     t1->next=newnode;
//                 }
//             }
//             else
//             {
//                 t1->val=sum;
//             }
//             // if(t1->next==0)
//             // {
//             //      cout<<t1->val<<" ";
//             // }
//             t1=t1->next;
//             t2=t2->next;
//         }
//        ListNode *temp=l1;
//         int data=0;
//         while(temp->next!=0)
//         {
//             data=temp->val;
//             temp=temp->next;
//         }
//         cout<<data;
//         if(data>=10)
//         {
//             ListNode *newnode=new ListNode(data/10);
//             temp->val=data%10;
//             temp->next=newnode;
//         }
//         return l1;
//     }
};
