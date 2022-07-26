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
    private:
    int len(ListNode* head)
    {
        int pow=1;
        ListNode *temp=head;
        while(temp->next!=0)
        {
            temp=temp->next;
            pow=pow*2;
        }
        return pow;
    }
public:
    int getDecimalValue(ListNode* head) {
        ListNode *temp=head;
        int l=len(head);
        int ans=0;
        while(temp!=0)
        {
            ans+=(l*temp->val);
            temp=temp->next;
            l/=2;
        }
        return ans;
    }
};
//alt approaches
/*int num = head.val;
        while (head.next != null) {
            num = (num << 1) | head.next.val;
            head = head.next;    
        }
        return num;
         num = 0
        while head:
            num = (num<<1) | head.val
            head = head.next
        return num/*
