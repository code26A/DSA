class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int t = 4;
        while (t--) {
            if (mat == target)
                return true;
            for (int i = 0; i < mat.size(); i++) {
                for (int j = 0; j < mat.size(); j++) {
                    if (i < j)
                        swap(mat[i][j], mat[j][i]);
                }
                reverse(mat[i].begin(), mat[i].end());
            }
        }

        return false;
    }
};