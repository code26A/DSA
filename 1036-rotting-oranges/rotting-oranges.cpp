class Solution {
public:
    bool safe(int i,int j,vector<vector<int>> &grid){
        return i>=0 && j>=0 && i<grid.size() && j<grid[0].size();
    }
    int orangesRotting(vector<vector<int>>& grid) {
         queue<pair<int,int>> q;
         int fresh=0;
         for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                     q.push({i,j});
                }else if(grid[i][j]==1) fresh++;
            }
         }
         int time=0;
         vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
         while(!q.empty()){
            int n=q.size();
            bool spread=false;
            for(int i=0;i<n;i++){
                auto [row,col]=q.front();
                q.pop();    
                for(auto &it:dir){
                    int nrow=row+it[0];
                    int ncol=col+it[1];
                    if(safe(nrow,ncol,grid) && grid[nrow][ncol]==1){
                        grid[nrow][ncol]=2;
                        fresh--;
                        spread=true;
                        q.push({nrow,ncol});
                    }
                }
            }
            if(spread) time++;
         }
         return fresh==0?time:-1;
    }
};