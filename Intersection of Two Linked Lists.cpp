/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    private:
    int len(ListNode *head)
    {
        ListNode *temp=head;
        int c=0;
        while(temp!=0)
        {
            c++;
            temp=temp->next;
        }
        return c;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=len(headA),l2=len(headB);
        int d=abs(l1-l2);
        ListNode *temp;
        ListNode *temp1;
        if(l1>l2)
        {
            int i=0;
            temp=headA;
            temp1=headB;
            while(temp!=0 && i!=d)
            {
                temp=temp->next;
                i++;
            }
        }
        else
        {
            int i=0;
            temp=headB;
            temp1=headA;
            while(temp!=0 && i!=d)
            {
                temp=temp->next;
                i++;
            }
        }
        while(temp!=0 && temp1!=0 && temp!=temp1)
        {
            temp=temp->next;
            temp1=temp1->next;
        }
        // if(te
        return temp;
    }
};
