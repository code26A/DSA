class Solution {
public:
    int solve(int row,int col, vector<vector<int>> &mat){
        int bound=mat[0].size();
        int count =0;
        for(int i=row;i<mat.size();i++){
            for(int j=col;j<bound;j++){
                if(mat[i][j]==1) count++;
                else bound=j;
            }
        }
        return count;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int ans=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                ans+=solve(i,j,mat);
            }
        }
        return ans;
    }
};