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
    int len(ListNode *head)
    {
        int c=0;
        ListNode *curr=head;
        while(curr!=0)
        {
            curr=curr->next;
            c++;
        }
        return c;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=len(head);
        ListNode *curr=head,*prev=0;
        int i=0;
        while(i<l-n && curr!=0)
        {
            prev=curr;
            curr=curr->next;
            i++;
        }
        if(prev!=0)
        {
            prev->next=curr->next;    
        }
        else
        {
            curr=head;
            if(head!=0)
            {
                head=curr->next;    
            }
        }
        // if(head==curr)
        // {
        //     head=head->next;
        // }
        delete curr;
        return head;
    }
};
