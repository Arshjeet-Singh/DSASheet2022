class MyStack {
public:
    queue<int> q,q1;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        if(q.empty())
        {
            return -1;
        }
        int i=0;
        int c=q.size()-1;
        int ans;
        while(!q.empty())
        {
            int a=q.front();
             q.pop();
            if(c==i)
            {
                ans=a;
                break;
            }
            else
            {
                q1.push(a);   
            }
            i++;
        }
        while(!q1.empty())
        {
            int a=q1.front();
            q1.pop();
            q.push(a);
        }
        return ans;
    } 
    int top() {
        if(q.empty())
        {
            return -1;
        }
        int i=0;
        int c=q.size()-1;
        int ans;
        while(!q.empty())
        {
            int a=q.front();
             q.pop();
            if(c==i)
            {
                ans=a;
                 q1.push(a);   
                break;
            }
            else
            {
                q1.push(a);   
            }
            i++;
        }
        while(!q1.empty())
        {
            int a=q1.front();
            q1.pop();
            q.push(a);
        }
        return ans;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
