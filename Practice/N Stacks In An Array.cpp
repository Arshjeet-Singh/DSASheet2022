#include <bits/stdc++.h> 
class NStack
{
public:
    int *arr;
    int *top;
    int *next;
    int n,s,free;
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n=N;
        s=S;
        arr=new int[s];
        top=new int[n];
        next=new int[s];
        for(int i=0;i<n;i++)
        {
            top[i]=-1;
        }
        for(int i=0;i<s;i++)
        {
            next[i]=i+1;
        }
        next[s-1]=-1;
        free=0;
        // Write your code here.
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(free==-1)
        {
            return false;
        }
        int index=free;
        arr[index]=x;
        free=next[index];
        next[index]=top[m-1];
        top[m-1]=index;
        return true;
        // Write your code here.
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(top[m-1]==-1)
        {
            return -1;
        }
       int index= top[m-1];
        top[m-1]=next[index];
        next[index]=free;
        int x=arr[index];
        free= index;
        return x;
        // Write your code here.
    }
};
