class Solution {
public:
    bool safe(int i, int j, vector<vector<int>>& mat) {
        return i >= 0 && j >= 0 && i < mat.size() && j < mat[0].size();
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        bool up = true, down = false;
        vector<int> ans;
        int i = 0, j = 0, n = mat.size(), m = mat[0].size();

        while (i < n && j < m) {
            cout << i << " " << j << endl;
            ans.push_back(mat[i][j]);
            if (up) {
                if (!safe(i - 1, j + 1, mat)) {
                    if (j == m - 1) {
                        i += 1;
                    } else
                        j += 1;
                    up = false;
                    down = true;
                } else {
                    i -= 1;
                    j += 1;
                }
            } else if (down) {
                if (!safe(i + 1, j - 1, mat)) {
                    if (i == n - 1) {
                        j += 1;
                    } else
                        i += 1;
                    up = true;
                    down = false;
                } else {
                    i += 1;
                    j -= 1;
                }
            }
        }
        return ans;
    }
};