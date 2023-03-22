//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool cmp(pair<double,Item> a,pair<double,Item> b)
    {
        return a.first > b.first;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,Item>> v;
        for(int i=0;i<n;i++)
        {
            double valw=(1.0*arr[i].value)/arr[i].weight;
            v.push_back({valw,arr[i]});
        }
        sort(v.begin(),v.end(),cmp);
        int cap=W;
        double ans=0;
        for(int i=0;i<n;i++)
        {
            if(v[i].second.weight<=cap)
            {
                cap-=v[i].second.weight;
                ans+=v[i].second.value;
            }
            else
            {
                ans+=v[i].first*cap;
                cap=0;
                // if(v[i].first)
            }
        }
        return ans;
        // Your code here
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends
