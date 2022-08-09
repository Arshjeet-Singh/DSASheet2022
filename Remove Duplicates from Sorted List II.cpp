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
        //o(1) space solution
        ListNode *temp=head;
        ListNode *dummy=new ListNode(-1);
        ListNode *prev=dummy;
        dummy->next=head;
        while(temp!=0 )
        {
            if(temp->next!=0 && temp->val==temp->next->val)
            {
                while(temp->next!=0 && temp->val==temp->next->val)
                {
                    temp=temp->next;
                }
                prev->next=temp->next;
            }
            else
            {
                // prev=prev->next;
                prev=temp;
            }
                  temp=temp->next;
        }
        return dummy->next;
        // ListNode *temp=head;
        // ListNode *prev;
        // int f=0;
        // unordered_map<int,int> mp;
        // while(temp!=0)
        // {
        //     mp[temp->val]++;
        //     temp=temp->next;
        // }
        // temp=head;
        // int fl=0;
        // while(head!=0 && mp[head->val]>1)
        // {
        //     fl=1;
        //     head=head->next;
        // }
        // temp=head;
        // while(temp!=0)
        // {
        //     // prev=temp;
        //     if(mp[temp->val]>1)
        //     {
        //         temp=temp->next;
        //         prev->next=temp;
        //     }
        //     else
        //     {
        //         prev=temp;
        //         temp=temp->next;
        //     }  
        // }
        // return head;
    }
};
