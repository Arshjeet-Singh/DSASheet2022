// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
       private:
vector<int> nextSmallerElement(int *arr, int n)
{
    stack<int> s;
        s.push(-1);
        vector<int> v(n);
        for(int i=n-1;i>=0;i--)
        {
            int curr=arr[i];
            while(s.top()!=-1 && arr[s.top()]>=curr)
            {
                s.pop();
            }
            v[i]=s.top(); 
             s.push(i);
        }
    return v;
    // Write your code here.
}
vector<int> leftSmaller(int n, int *a){
        stack<int> s;
        s.push(-1);
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            int curr=a[i];
            while(s.top()!=-1 && a[s.top()]>=curr)
            {
                s.pop();
            }
            v[i]=s.top();
            s.push(i);
        }
        return v;
        // code here
    }
    int largestRectangleArea(int * heights,int n) {
        // int n=heights.size();
        vector<int> next(n);
        next=nextSmallerElement(heights,n);
        vector<int> prev(n);
            prev=leftSmaller(n,heights);
        int ar=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int l=heights[i];
            if(next[i]==-1)
            {
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            ar=max(ar,l*b);
        }
        return ar;
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        int ans=largestRectangleArea(M[0],m);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j]!=0)
                {
                    M[i][j]+=M[i-1][j];
                }
                else
                {
                    M[i][j]=0;
                }
            }
            ans=max(ans,largestRectangleArea(M[i],m));
        }
        return ans;
        // Your code here
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends
