class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int min_i=-1,max_i=-1,min_j=-1,max_j=-1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    if(max_i==-1) max_i=i;
                    else max_i=max(max_i,i);

                    if(max_j==-1) max_j=j;
                    else max_j=max(max_j,j);

                    if(min_i==-1) min_i=i;
                    else min_i=min(min_i,i);

                    if(min_j==-1) min_j=j;
                    else min_j=min(min_j,j);
                }
            }
        }
        return (max_i-min_i+1) * (max_j-min_j+1);
    }
};