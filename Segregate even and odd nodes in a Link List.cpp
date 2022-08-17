//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        Node *edummy=new Node(-1);
        Node *odummy=new Node(-1);
        Node *temp=head,*ohead=odummy,*ehead=edummy;
        while(temp!=0)
        {
            if((temp->data)%2==0)
            {
                // cout<<temp->data<<" ";
                edummy->next=temp;
                temp=temp->next;
                edummy=edummy->next;
            }
            else
            {
                // cout<<temp->data<<" ";
                odummy->next=temp;
                temp=temp->next;
                odummy=odummy->next;
            }
            // temp=temp->next;
        }
        edummy->next=ohead->next;
        odummy->next=0;
        return ehead->next;
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends
