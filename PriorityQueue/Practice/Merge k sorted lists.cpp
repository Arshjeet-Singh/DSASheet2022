/************************************************************

    Following is the linked list node structure

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
#include<queue>
class compare
{
    public:
    bool operator()(Node<int>* a,Node<int> *b)
    {
        return a->data > b->data;
    }
};
Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    int n=listArray.size(); 
 if(n==0)
 {
     return 0;
 }     priority_queue<Node<int>*,vector<Node<int>*>,compare> pq;
    for(int i=0;i<n;i++)
    {
        if(listArray[i]!=0)
        {
            pq.push(listArray[i]);    
        }
    }
    Node<int> *head=0;
    Node<int> *tail=0;
    while(!pq.empty())
    {
        Node<int>*temp=pq.top();
        pq.pop();
        if(temp->next)
        {
             pq.push(temp->next);   
        }
        if(head==0)
        {
            head=tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=tail->next;
        }
    }
    return head;
    // Write your code here.
}
