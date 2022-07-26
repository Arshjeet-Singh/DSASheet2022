class Solution {
    
public:
 
    string helper(int n,string s)
    {
          string ones[]={"","One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine ",
    "Ten ","Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen "      ,"Nineteen "        };
    string tens[]={"","","Twenty ","Thirty ","Forty ","Fifty ","Sixty ","Seventy ","Eighty ",
                   "Ninety "};
        string ans="";
        if(n>99)
        {
            int h=n/100;
            ans=ans+ones[h]+"Hundred ";
            // n=n%100;
        }
        if((n%100)>19)
        {
            // if(ones[n%10]!="")
                ans=ans+tens[(n%100)/10]+""+ones[(n%100)%10];
            // else
            //     ans=ans+tens[n/10]+""+ones[n%10];
                
        }
        else
        {
            ans+=ones[n%100]+"";
        }
        if(n)
        {
            ans=ans+s;
        }
        return ans;
    }
    string numberToWords(int num) {
        if(num==0)
        {
            return "Zero";
        }
        string res="";
        res+=helper(num/1000000000,"Billion ");
        res+=helper((num/1000000)%1000,"Million ");
        res+=helper((num/1000)%1000,"Thousand ");
        res+=helper(num%1000,"");
        return res.substr(0,res.length()-1);
        }
        
};
