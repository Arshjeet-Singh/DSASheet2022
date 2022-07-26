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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==0 || head->next==0)
        {
            return head;
        }
        ListNode* p1=head,*p2=head;
        while(p1 && p1->next)
        {
            ListNode *nextnode=p1->next;
            if(p1->val==nextnode->val)
            {
                p1->next=nextnode->next;
            }
            else
            {
                p1=nextnode;
            }
        }
        return head;
      // seond approach
        while(p2!=0)
        {
            while(p2!=0 && p1->val==p2->val)
            {
                p2=p2->next;
            }
                p1->next=p2;
                p1=p2;
        }
        return head;
    }
};
