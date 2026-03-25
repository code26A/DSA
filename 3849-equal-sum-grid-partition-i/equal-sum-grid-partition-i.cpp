class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<long long>> pref_row(n,vector<long long>(m)),pref_col(n,vector<long long>(m));
        for(int i=0;i<n;i++){
            pref_row[i][0]=grid[i][0];
        }
        for(int j=0;j<m;j++){
                pref_col[0][j]=grid[0][j];
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                pref_row[i][j]=pref_row[i][j-1]+grid[i][j];
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                pref_col[i][j]=pref_col[i-1][j]+grid[i][j];
            }
        }
        for(int i=0;i<n-1;i++){
            long long  sum1=0,sum2=0;
            for(int j=0;j<m;j++){
                sum1+=(pref_col[n-1][j]-pref_col[i][j]);
                sum2+=pref_col[i][j];
            }
            if(sum1==sum2) return true;
        }
        for(int j=0;j<m-1;j++){
            long long sum1=0,sum2=0;
            for(int i=0;i<n;i++){
                sum1+=pref_row[i][j];
                sum2+=(pref_row[i][m-1] - pref_row[i][j]);
            }
            if(sum1==sum2) return true;
        }
        return false;
    }
};