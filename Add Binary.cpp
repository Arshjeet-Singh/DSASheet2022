//Approach 2
class Solution {
public:
    string addBinary(string a, string b) {
        // string ans=0;
      //Approach 1
//        string ans="";
//         int m=a.length(),n=b.length();
//         int i=0,sum=0,carry=0;
//         while(i<m || i<n || carry!=0)
//         {
//             int x=0;
//             if(i<m && a[m-i-1]=='1')
//             {
//                 x=1;
//             }
//             int y=0;
//             if(i<n && b[n-i-1]=='1')
//             {
//                 y=1;
//             }
//             ans=to_string((x+y+carry)%2)+ans;
//             carry=(x+y+carry)/2;
//             i++;
//         }
//         return ans;
        int n=a.length(),m=b.length();
        int size=max(m,n);
        if(size==m && n!=m)
        {
            while(a.length()!=m)
            {
                a='0'+a;
            }
            // reverse(a.begin(),a.end());
            cout<<a<<"2a"<<endl;
        }
        else if(size==n && n!=m)
        {
           while(b.length()!=n)
            {
                b='0'+b;
            } 
            // reverse(b.begin(),b.end());
            cout<<b<<"2b"<<endl;
        }
        char sum,carry='0';
        string ans="";
        for(int i=size-1;i>=0;i--)
        {
            if(a[i]=='1' && b[i]=='1' && carry=='0')
            {
                sum='0';
                carry='1';
            }
            else if(a[i]=='1' && b[i]=='1' && carry=='1')
            {
                sum='1';
                carry='1';
            }
            else if(a[i]=='1' && b[i]=='0' && carry=='1' || (a[i]=='0' && b[i]=='1' && carry=='1'))
            {
                sum='0';
                carry='1';
            }
            else if(a[i]=='1' && b[i]=='0' && carry=='0' || (a[i]=='0' && b[i]=='1' && carry=='0') ||(a[i]=='0' && b[i]=='0' && carry=='1'))
            {
                sum='1';
                carry='0';
            }
             else if(a[i]=='0' && b[i]=='0' && carry=='0')
            {
                sum='0';
                carry='0';
            }
            if(i==0 && carry=='1')
            {
                 ans=ans+sum+carry;
            }
            else
            {
                 ans+=sum;
            }
        }
        reverse(ans.begin(),ans.end());
         cout<<ans<<endl;
        return ans;
    }
};
