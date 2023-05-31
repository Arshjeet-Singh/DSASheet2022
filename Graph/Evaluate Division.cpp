// class Solution {
// public:
// void dfs(unordered_map<string,unordered_map<string,double>> &gr,string c,string d,double ans,double temp,unordered_set<string> &vis)
// {
//     if(vis.find(c)!=vis.end())
//     {
//         return;
//     }
//     vis.insert(c);
//     if(c==d)
//     {
//         ans=temp;
//         return;
//     }
//     for(auto ne:gr[c])
//     {
//         dfs(gr,ne.first,d,ans,temp*ne.second,vis);
//         // temp=temp*ne.second;
//     }
// }
//     vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//         unordered_map<string,unordered_map<string,double>> gr;
//         for(int i=0;i<equations.size();i++)
//         {
//             string dividend=equations[i][0];
//             string divisor=equations[i][1];
//             gr[dividend][divisor]=values[i];
//             gr[divisor][dividend]=1.0/values[i];
//         }
//         vector<double> ans;
//         for(int i=0;i<queries.size();i++)
//         {
//             string c=queries[i][0];
//             string d=queries[i][1];
//             if(gr.find(c)==gr.end() || gr.find(d)==gr.end())
//             {
//                 ans.push_back(-1);
//             }
//             else
//             {
//                 unordered_set<string> vis;
//                 double a=-1.0,temp=1.0;
//                 dfs(gr,c,d,a,temp,vis);
//                 ans.push_back(a);
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
void dfs(string node, string& dest, unordered_map<string,
unordered_map<string, double>>& gr, unordered_set<string>& vis, double& ans,
double temp) {

if(vis.find(node) != vis.end()) return;
vis.insert(node);
if(node == dest){
ans = temp;
return;
}
for(auto ne : gr[node]){
dfs(ne.first, dest, gr, vis, ans, temp * ne.second);
}
}
unordered_map<string, unordered_map<string, double>> buildGraph(const
vector<vector<string>>& equations, const vector<double>& values) {
unordered_map<string, unordered_map<string, double>> gr;
for (int i = 0; i < equations.size(); i++) {
string dividend = equations[i][0];
string divisor = equations[i][1];
double value = values[i];
gr[dividend][divisor] = value;
gr[divisor][dividend] = 1.0 / value;
}
return gr;
}
vector<double> calcEquation(vector<vector<string>>& equations,
vector<double>& values, vector<vector<string>>& queries) {

unordered_map<string, unordered_map<string, double>> gr =

buildGraph(equations, values);
vector<double> finalAns;
for (auto query : queries) {
string dividend = query[0];
string divisor = query[1];
if (gr.find(dividend) == gr.end() || gr.find(divisor) ==

gr.end()) {

finalAns.push_back(-1.0);
} else {
unordered_set<string> vis;
double ans = -1, temp=1.0;
dfs(dividend, divisor, gr, vis, ans, temp);
finalAns.push_back(ans);
}

}
return finalAns;
}
};
