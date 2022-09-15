//recursive approach
void help(stack<int>&inputStack, int N,int count)
{
    if(count==N/2)
    {
        inputStack.pop();
        return;
    }
    int a=inputStack.top();
    inputStack.pop();
    help(inputStack,N,count+1);
    inputStack.push(a);
}
void deleteMiddle(stack<int>&inputStack, int N){
     help(inputStack,N,0);
    /*
    if(N==1)
    {
        inputStack.pop();
//         s.pop
        return;
    }
	int sz=(inputStack.size()-1)/2;
    int c=0;
    stack<int> s;
    while(!inputStack.empty() && c!=(sz))
    {
        int a=inputStack.top();
        inputStack.pop();
        s.push(a);
        c++;
    }
   if(!inputStack.empty())
   {
    inputStack.pop();       
   }
    while(!s.empty())
    {
        int a=s.top();
        inputStack.push(a);
        s.pop();
    }
//     if(inputStack.size()==N/2)
//     {
//         return;
//     }
//     int a=inputStack.top();
//     inputStack.pop();
//     deleteMiddle(inputStack,N-1);
//     inputStack.push(a);
   // Write your code here
   */
}
