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
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=0 && head->val==val)
        {
            head=head->next;
        }
        ListNode *temp=head,*prev=0;
        while(temp!=0)
        {
            while( temp!=0 && temp->val==val)
            {
                prev->next=temp->next;
                temp=temp->next;
            }
            prev=temp;
            if(temp!=0)
            {
                cout<<temp->val<<" ";
                temp=temp->next;    
            }
        }
         return head; 
    }
};
