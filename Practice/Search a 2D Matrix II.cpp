class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int rowind=0,colind=col-1;
        while(rowind<row && colind>=0)
        {
            int ele=matrix[rowind][colind];
            if(target==ele)
            {
                return 1;
            }
            else if(ele>target)
            {
                colind--;
            }
            else
            {
                rowind++;
            }
        }
        return 0;
    }
};
