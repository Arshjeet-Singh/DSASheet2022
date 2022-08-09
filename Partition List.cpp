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
    ListNode* partition(ListNode* head, int x) {
        ListNode *highh=new ListNode(-1);
        ListNode *smallh=new ListNode(-1);
        ListNode *temp=head,*h=highh,*s=smallh;
        // ubnordered_map<ListNode *,int> mp;
        while(temp!=0)
        {
            if(temp->val<x)
            {
                smallh->next=temp;
                smallh=smallh->next;
                // cout<<smallh->val<<endl;
            }
            else
            {
                highh->next=temp;
                highh=highh->next;
            }
            temp=temp->next;
        }
        smallh->next=h->next;
        highh->next=0;
        return s->next;
    }
};
