class Solution {
public:
vector<int> nextSmallerElement(vector<int> &arr, int n)
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
vector<int> leftSmaller(int n, vector<int> &a){
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
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> next(n);
        next=nextSmallerElement(heights,n);
        vector<int> prev(n);
            prev=leftSmaller(n,heights);
        int ar=INT_MIN;
        for(int i=0;i<heights.size();i++)
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> height(matrix[0].size(),0);
        int maxi=INT_MIN;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<height.size();j++)
            {
                if(matrix[i][j]=='1')
                {
                    height[j]+=1;
                }
                else
                {
                    height[j]=0;
                }
            }
            maxi=max(maxi,largestRectangleArea(height));
        }   
        return maxi;
    }
};
