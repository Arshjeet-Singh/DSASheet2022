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
    void insertattail(ListNode *&head,ListNode *&tail,int d)
    {
        ListNode *newnode=new ListNode(d);
        if(head==0 || tail==0)
        {
            head=tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
    }
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1=reverse(l1);
        ListNode *temp=h1;
         // while(temp!=0)
         // {
         //     cout<<temp->val<<" ";
         //     temp=temp->next;
         // }
        // cout<<endl;
        ListNode* h2=reverse(l2);
        int d1=0,d2=0;int carr=0;
        ListNode *anshead=0,*anstail=0;
        while(h1!=0|| h2!=0 || carr!=0)
        {
            d1=0; d2=0; 
            if(h1!=0)
            {
                d1=h1->val;
            }
            if(h2!=0)
            {
                d2=h2->val;
            }
            int sum=d1+d2+carr;
            int digit=sum%10;
            insertattail(anshead,anstail,digit);
            if(h1!=0)
            {
              h1=h1->next;   
            }
            if(h2!=0)
            {
                h2=h2->next;
            }
            carr=sum/10;
        }
        h1=reverse(h1);
        h2=reverse(h2);
        return reverse(anshead);
    }
};
