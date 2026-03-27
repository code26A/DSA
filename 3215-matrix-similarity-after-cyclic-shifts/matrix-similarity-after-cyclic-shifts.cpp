class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> temp=mat;
        k=k%mat[0].size();
        for(int i=0;i<mat.size();i++){
            if(i%2!=0){
                reverse(mat[i].begin(),mat[i].end());
                reverse(mat[i].begin(),mat[i].begin()+k);
                reverse(mat[i].begin()+k,mat[i].end());
            }else{
                reverse(mat[i].begin(),mat[i].begin()+k);
                reverse(mat[i].begin()+k,mat[i].end());
                reverse(mat[i].begin(),mat[i].end());
            }
        }
        if(temp==mat) return true;
        return false;
    }
};