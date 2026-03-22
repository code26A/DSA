class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) fresh++;
            }
        }
        int time=0;
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            int lev=q.size();
            bool flag=false;
            for(int i=0;i<lev;i++){
                auto [row,col]=q.front();
                q.pop();
                for(auto it: dir){
                    int nx=row+it[0];
                    int ny=col+it[1];
                    if(nx<n && ny<m && nx>=0 && ny>=0 && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                        flag=true;
                        fresh--;
                    }
                }
            }
            if(flag) time++;
        }
        if(fresh!=0) return -1;
        return time;
    }
};