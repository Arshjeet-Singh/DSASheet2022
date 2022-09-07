/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
Node *detect(Node *head)
{
    if(head==0)
    {
        return 0;
    }
    Node *slow=head,*fast=head;
    while(slow !=0 && fast!=0 && fast->next!=0)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            return slow;    
        }
    }  
    return 0;    
}
Node *startnode(Node *head)
{
    if(head==0)
    {
        return 0;
    }
    Node *cycle=detect(head);
    if(cycle==0)
    {
        return 0;
    }
    Node *slow=head;
    while(slow!=cycle)
    {
        slow=slow->next;
        cycle=cycle->next;
    }
    return slow;
}
Node *removeLoop(Node *head)
{
    if(head==0)
    {
        return head;
    }
    //start of loop
    Node *intersect=startnode(head);
    if(intersect==0)
    {
        return head;
    }
    Node *temp=intersect;
    while(temp->next!=intersect)
    {
        temp=temp->next;
    }
    temp->next=0;
    return head;
    // Write your code here.
}
