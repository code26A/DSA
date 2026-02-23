class Solution {
public:
    bool safe(int i,int j,vector<vector<char>> &grid){
        return i>=0 && j>=0 && i<grid.size() && j<grid[0].size();
    }
    void dfs(int row,int col,vector<vector<bool>> &vis,vector<vector<char>> &grid){
        if(!safe(row,col,grid) || vis[row][col] || grid[row][col]=='0') return;
        vis[row][col]=true;
        dfs(row+1,col,vis,grid);
        dfs(row,col+1,vis,grid);
        dfs(row-1,col,vis,grid);
        dfs(row,col-1,vis,grid);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return ans;
    }
};