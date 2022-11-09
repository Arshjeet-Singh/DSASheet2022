#include <bits/stdc++.h> 
class node{
     public:
  int data;
    int i;
    int j;
    node(int data,int r,int c)
    {
        this->data=data;
        i=r;
        j=c;
    }
};
class compare
{
  public:
    bool operator()(node* a,node*b)
    {
        return a->data>b->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*,vector<node*>,compare> pq;
    for(int i=0;i<kArrays.size();i++)
    {
        node *temp=new node(kArrays[i][0],i,0);
        pq.push(temp);
    }
    vector<int> ans;
    while(!pq.empty())
    {
        node *temp=pq.top();
        pq.pop();
        ans.push_back(temp->data);
        if(temp->j+1<kArrays[temp->i].size())
        {
            node *temp1=new node(kArrays[temp->i][temp->j+1],temp->i,temp->j+1);
            pq.push(temp1);
        }
    }
    return ans;
    // Write your code here. 
}
