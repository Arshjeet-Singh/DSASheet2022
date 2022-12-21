//can be done using trie also by maintaining the childcount variable int the structure if it is 1 add that char to answer else return the answer

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans="";
    int mlf=0;
    string init=arr[0];
    for(int i=0;i<init.length();i++)
    {
        char initc=init[i];
        for(int j=1;j<n;j++)
        {
            if(init[i]!=arr[j][i])
            {
                 mlf=1;
                break;
            }
        }
        if(mlf==0)
        {
            ans+=init[i];
        }
        else
        {
            break;
        }
    }
    return ans;
    // Write your code here
}


