class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s="";
        while(columnNumber>0)
        {
            
            int r=columnNumber%26;
            if(r==0)
            {
                 s=char(26+64)+s;
                columnNumber/=26;
                columnNumber-=1;
            }
            else
            {
                 s=char(r+64)+s;
                columnNumber/=26;
            }
            // s=char(r+64)+s; 
        }
        return s;  
    }
};
