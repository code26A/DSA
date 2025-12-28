class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int cols = grid[0].size();
        
        for (auto row : grid) {
            
            int left = 0, right = cols - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (row[mid] < 0) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            
            count += cols - left;
        }
        
        return count;
    }
};