class Solution {
public:
void helper(string digits,string output,vector<string> &ans,int ind,vector<string> map)
{
    if(ind>=digits.size())
    {
        ans.push_back(output);
        return;
    }
    int num=digits[ind]-'0';
    string v=map[num];
    for(int i=0;i<v.length();i++)
    {
        output.push_back(v[i]);
        helper(digits,output,ans,ind+1,map);
        output.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0)
        {
            return ans;
        }
        string output="";
        vector<string> map={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        helper(digits,output,ans,0,map);
        return ans;
    }
};
