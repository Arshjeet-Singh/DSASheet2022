#include <bits/stdc++.h> 
class NQueue{
public:
    int *arr,*front,*rear,*next;
    int freespot,k,N;
    // Initialize your data structure.
    NQueue(int n, int s){
        k=n;
        N=s;
        arr=new int[N];
        next=new int[N];
        for(int i=0;i<N;i++)
        {
            next[i]=i+1;
        }
        next[N-1]=-1;
        front=new int[k];
        rear=new int[k];
        for(int i=0;i<k;i++)
        {
            front[i]=-1; rear[i]=-1;
        }
        freespot=0;
        // Write your code here.
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        if(freespot==-1)
        {
            return false;
        }
        int ind=freespot;
        freespot=next[ind];
       
        if(front[m-1]==-1)
        {
            front[m-1]=ind;
        }
        else
        {
            next[rear[m-1]]=ind;
        }
        next[ind]=-1;
        rear[m-1]=ind;
         arr[ind]=x;
        return true;
        // Write your code here.
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        if(front[m-1]==-1)
        {
            return -1;
        }
        int ind=front[m-1];
        int x=arr[ind];
        front[m-1]=next[ind];
        next[ind]=freespot;
        freespot=ind;
        return x;
        // Write your code here.
    }
};
