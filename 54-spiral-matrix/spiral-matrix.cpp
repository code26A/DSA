class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int top=0,bottom=n-1,left=0,right=m-1;
        int flag=n*m;
        vector<int> ans;
        while(flag){
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
                flag--;
            }
            top++;
            if(!flag) break;
            for(int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
                flag--;
            }
            right--;
            if(!flag) break;
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
                flag--;
            }
            bottom--;
            if(!flag) break;
            for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
                flag--;
            }
            left++;
            if(!flag) break;
        }
        return ans;
    }
};