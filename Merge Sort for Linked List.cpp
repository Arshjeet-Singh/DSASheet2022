//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/
class Solution{
  public:
  Node *middle(Node *head)
  {
      if(head==0 || head->next==0)
      {
          return head;
      }
      Node *slow=head;
      Node *fast=head->next;
      while(fast!=0 && fast->next!=0)
      {
          slow=slow->next;
          fast=fast->next->next;
      }
      return slow;
  }
  Node *merge(Node *left,Node *right)
  {
      if(left==0)
      {
          return right;
      }
      if(right==0)
      {
          return left;
      }
      Node *ans=new Node(-1);
      Node *temp=ans;
      while(left!=0 && right!=0)
      {
          if(left->data < right->data)
          {
              temp->next=left;
              left=left->next;
              temp=temp->next;
          }
          else
          {
              temp->next=right;
              right=right->next;
              temp=temp->next;
          }
      }
      while(left!=0)
      {
          temp->next=left;
          left=left->next;
          temp=temp->next;
      }
      while(right!=0)
      {
          temp->next=right;
          right=right->next;
          temp=temp->next;
      }
      ans=ans->next;
      return ans;
  }
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        if(head==0 || head->next==0)
        {
            return head;
        }
        Node *mid=middle(head);
        Node *left=head;
        Node *right=mid->next;
        mid->next=0;
        left=mergeSort(left);
        right=mergeSort(right);
        return merge(left,right);
        // your code here
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends
