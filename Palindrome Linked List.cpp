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
      ListNode *curr=head,*prev=0,*nextnode=0;
      while(curr!=0)
      {
          nextnode=curr->next;
          curr->next=prev;
          prev=curr;
          curr=nextnode;
      }
      return prev;
  }
    //Function to check whether the list is palindrome.
    bool isPalindrome(ListNode *head)
    {
        if(head==0 || head->next==0)
        {
            return true;
        }
        ListNode *temp,*mid=middle(head);
        cout<<mid->val<<endl;
        temp=mid->next;
        mid->next=reverse(temp);
        ListNode *h1=head,*h2=mid->next;
        while(h1!=0 && h2!=0)
        {
            if(h1->val!=h2->val)
            {
                cout<<h1->val<<" "<<h2->val<<endl;
                return false;
            }
            h1=h1->next;
            h2=h2->next;
        }
        temp=mid->next;
        mid->next=reverse(temp);
        return true;
        //Your code here
    }
    // ListNode *reverse(ListNode* head)
    // {
    //     if(head==0 || head->next==0)
    //     {
    //         return head;
    //     }
    //     ListNode *h=reverse(head->next);
    //     head->next->next=head;
    //     head->next=0;
    //     return h;
    // }
    // ListNode *midpoint(ListNode* head)
    // {
    //     if(head==0 || head->next==0)
    //     {
    //         return head;
    //     }
    //     ListNode *slow=head;
    //     ListNode *fast=head->next;
    //     while(fast!=0 && fast->next!=0)
    //     {
    //         slow=slow->next;
    //         fast=fast->next->next;
    //     }
    //     return slow;
    // }
    // int len(ListNode *head)
    // {
    //     int c=0;
    //     ListNode *temp=0;
    //     while(temp!=0)
    //     {
    //         c++;
    //         temp=temp->next;
    //     }
    //     return c;
    // }
    // bool isPalindrome(ListNode* head) {
    //     if(head==0 ||head->next==0)
    //     {
    //         return true;
    //     }
    //     if(head->next->next==0)
    //     {
    //         if(head->val==head->next->val)
    //         {
    //             return true;
    //         }
    //         else
    //         {
    //             return false;
    //         }
    //     }
    //     ListNode *mid=midpoint(head);
    //     ListNode*t1=head,*t2=head,*t3;
    //     int l1=len(head),l2;
    //     if(l1%2!=0)
    //     {
    //          while(t1!=0 && t1!=mid)
    //         {
    //             t2=t1;
    //             t1=t1->next;
    //         }
    //         t2->next=0;
    //         ListNode *rmid=reverse(t1);
    //         l1=len(head);
    //         l2=len(rmid);
    //             t1=head,t2=rmid;
    //     }
    //     else
    //     {
    //         while(t1!=0 && t1!=mid)
    //         {
    //             t2=t1;
    //             t1=t1->next;
    //         }
    //         t3=t1->next;
    //         t1->next=0;
    //         ListNode *rmid=reverse(t3);
    //         l1=len(head);
    //         l2=len(rmid);
    //             t1=head,t2=rmid;
    //     }
    //     while(t1!=0 && t2!=0)
    //     {
    //         if(t1->val==t2->val)
    //         {
    //             t1=t1->next;
    //             t2=t2->next;
    //         }
    //         else
    //         {
    //             return false;
    //             break;
    //         }
    //     }
    //     return true;
    // }
};
