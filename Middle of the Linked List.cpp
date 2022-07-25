// can be done using slow and fast approach as well
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
    int leng(ListNode *head)
    {
        int len=0;
        ListNode *temp=head;
        while(temp!=0)
        {
            len++;
            temp=temp->next;
        }
        return len;
    }
    ListNode* middleNode(ListNode* head) {
        ListNode *temp=head;
        int l=leng(head);
        int i=0;
        while(i<l/2)
        {
            temp=temp->next;
            i++;
        }
        return temp;
    }
};
