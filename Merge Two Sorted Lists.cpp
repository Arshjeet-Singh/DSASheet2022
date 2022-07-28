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
     ListNode* solve(ListNode* list1, ListNode* list2)
     {
         ListNode *curr1 = list1;
         ListNode *next1 = curr1->next,*curr2 =list2;
         ListNode*next2 =curr2->next;
         if(next1==0)
         {
             if(curr1->val<=curr2->val)
             {
                 curr1->next=curr2;
                 return curr1;
             }
         }
         while(curr2!=0 && next1!=0)
         {
             if(curr1->val<=curr2->val &&(curr2->val<=next1->val))
             {
                 curr1->next=curr2;
                 next2=curr2->next;
                 curr2->next=next1;
                 curr1=curr2;
                 curr2=next2;
             }
             else
             {
                 curr1=next1;
                 next1=next1->next;
                 if(next1==0)
                 {
                     curr1->next=curr2;
                     return list1;
                 }
             }
         }
         return list1;
     }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==0 )
        {
            return list2;
        }
        if(list2==0 )
        {
            return list1;
        }
        if(list1->val<=list2->val)
        {
            return solve(list1,list2);
        }
        else
        {
            return solve(list2,list1);
        }
        return 0;
//       while(t1!=0 && t2!=0)
//       {
//           if(t1->val<=t2->val)
//           {
//               while(t1!=0 && t2!=0 && t1->val <=t2->val)
//               {
//                   t1=t1->next;
//               }
//               if(t1)
//               h1=t1->next;
//               t1->next=t2;
//               t1=h1;
//           }
//           else
//           {
//               while(t2!=0 && t1!=0 && t2->val<=t1->val)
//               {
//                   t2=t2->next;
//               }
//               if(t2!=0)
//               {
//                   h2=t2->next;
//               t2->next=t1;
//               t2=h2;
//               }
              
//           }
//       }
//         if(f==1)
//         {
//             return list1;
//         }
//         else
//         {
//             return list2;
//         }
    }
};
