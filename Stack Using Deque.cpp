#include <bits/stdc++.h> 
class Stack
{
public:
     int *arr;
    int f,r,N,sz;
    // Initialize your data structure.
    Stack()
    {
         N=100001;
        f=r=-1;
        arr=new int[N];
        sz=0;
    }

    // Pushes 'X' into the stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x)
    {
        if((f==0 && r==N-1) ||(f!=0 && r==(f-1)%(N-1)))
        {
            return false;
        }
        if(f==-1 && r==-1)
        {
            f=r=0;
        }
        else if(f!=0 && r==N-1)
        {
            r=0;
        }
        else
        {
            r++;
        }
        arr[r]=x;
        sz++;
        return true;
        // Write your code here.
    }

    // Pops top element from Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop()
    {
        if(f==-1 && r==-1)
        {
            return -1;
        }
        int a=arr[r];
        arr[r]=-1;
        if(f==r)
        {
            f=r=-1;
        }
        else if(r==0)
        {
            r=N-1;
        }
        else
        {
            r--;
        }
        sz--;
        return a;
        // Write your code here.
    }

    // Returns the topmost element of the stack. In case the stack is empty, it returns -1.
    int top()
    {
        if(f==-1 && r==-1)
        {
            return -1;
        }
        int a=arr[r];
        return a;
        // Write your code here.
    }

    // Returns true if the stack is empty, otherwise false.
    bool isEmpty()
    {
        if(f==-1 && r==-1)
        {
            return true;
        }
        return false;
        // Write your code here.
    }

    // Returns the number of elements currently present in the stack.
    int size()
    {
        return sz;
        // Write your code here.
    }
};
