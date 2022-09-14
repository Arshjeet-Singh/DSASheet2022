class TwoStack {

public:
    int *arr;
    int top1;
    int top2;
    int size;
    // Initialize TwoStack.
    TwoStack(int s) {
        arr= new int[s];
        this->size=s;
        this->top1=-1;
        this->top2=s;
        // Write your code here.
    }
    // Push in stack 1.
    void push1(int num) {
        if(top2-top1>1)
        {
             top1++;
            arr[top1]=num;
//             size--;
        }
        // Write your code here.
    }

    // Push in stack 2.
    void push2(int num) {
        if(top2-top1>1)
        {
            top2--;
            arr[top2]=num;
//             size--;
        }
        // Write your code here.
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1==-1)
        {
            return -1;
        }
        int toreturn=arr[top1];
        top1--;
//         size++;
        return toreturn;
        // Write your code here.
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(top2==size)
        {
            return -1;
        }
        int toreturn=arr[top2];
        top2++;
//         size++;
        return toreturn;
        // Write your code here.
    }
};
