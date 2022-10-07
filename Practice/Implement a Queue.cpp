#include <bits/stdc++.h> 
class Queue {
public:
    int *arr;
    int fron,rear,size;
//     queue<int> q;
    Queue() {
        size=100001;
        arr=new int[size];
        fron=rear=0;
        // Implement the Constructor
    }
    /*----------------- Public Functions of Queue -----------------*/
    bool isEmpty() {
        if(fron==rear)
        {
            return true;
        }
        return false;
        // Implement the isEmpty() function
    }
    void enqueue(int data){
        if(rear==size)
        {
            return;
        }
        else
        {
            arr[rear]=data;
            rear++;
        }
//         q.push(data);
        // Implement the enqueue() function
    }
    int dequeue() {
        if(fron==rear)
        {
            return -1;
        }
        int a=arr[fron];
        arr[fron]=-1;
        fron++;
        if(fron==rear)
        {
            fron=rear=0;
        }
        return a;
//         q.pop();
//         return a;
        // Implement the dequeue() function
    }

    int front() {
        if(fron==rear)
        {
            return -1;
        }
        int a=arr[fron];
        return a;
        // Implement the front() function
    }
};
