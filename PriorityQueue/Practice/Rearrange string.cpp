#include <bits/stdc++.h> 
string reArrangeString(string &s)
{
    string a1="possible";
    string a2="not possible";
    unordered_map<int,int> mp;
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        mp[s[i]]++;
    }
    priority_queue<pair<int,char>> pq;
    for(auto i:mp)
    {
        pq.push(make_pair(i.second,i.first));
    }
    pair<int,char> g={-1,'$'};
    string ans="";
    while(!pq.empty())
    {
        auto temp=pq.top();
        pq.pop();
        ans.push_back(temp.second);
        temp.first--;
        if(g.first>0)
        {
            pq.push(g);
        }
        g=temp;
    }
    if(ans.length()==n)
    {
        return ans;
    }
    return a2;
	// Write your code here.
}
