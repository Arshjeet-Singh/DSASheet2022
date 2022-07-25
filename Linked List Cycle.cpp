/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==0 || head->next==0)
        {
            return false;
        }
        ListNode *slow=head,*fast=head;
        do{
            
            slow=slow->next;
            if(fast->next!=0)
            {
                 fast=fast->next->next;
            }
            else
            {
                return false;
            }
           
        }while(slow!=fast && fast!=0 && fast->next!=0);
        if(slow==fast)
        {
            return true;
        }
        if(fast==0 || fast->next==0)
        {
            return false;
        }
        return false;
    }
};
//found this to be cleaner then my code
bool hasCycle(ListNode *head) {
	
		// if head is NULL then return false;
        if(head == NULL)
            return false;
        
		// making two pointers fast and slow and assignning them to head
        ListNode *fast = head;
        ListNode *slow = head;
        
		// till fast and fast-> next not reaches NULL
		// we will increment fast by 2 step and slow by 1 step
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
			
			// At the point if fast and slow are at same address
			// this means linked list has a cycle in it.
            if(fast == slow)
                return true;
        }
        
		// if traversal reaches to NULL this means no cycle.
        return false;
    }
