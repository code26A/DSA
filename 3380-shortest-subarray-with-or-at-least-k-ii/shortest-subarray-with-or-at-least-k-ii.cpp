class Solution {
public:
    int OR_func(int start, int end, vector<vector<int>>& prefix_bits) {
        int k = 0;
        for (int i = 0; i < 31; i++) {
            int ones = 0;
            if (start == 0) {
                ones = prefix_bits[i][end];
            } else {
                ones = prefix_bits[i][end] - prefix_bits[i][start - 1];
            }
            if (ones >= 1)
                k |= (1 << i);
        }
        return k;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        // creating the bit array

        vector<vector<int>> bits(31, vector<int>(n));
        for (int i = 0; i < 31; i++) {
            for (int j = 0; j < n; j++) {
                bits[i][j] = (nums[j] >> i) & 1;
            }
        }

        // creating the prefix bit array

        vector<vector<int>> prefix_bits(31, vector<int>(n));

        for (int i = 0; i < 31; i++) {
            prefix_bits[i][0] = bits[i][0];
            for (int j = 1; j < n; j++) {
                prefix_bits[i][j] = prefix_bits[i][j - 1] + bits[i][j];
            }
        }

        // traversing the array

        int left = 0, right = 0;
        int mini = 1e9;
        int windowOr = 0;
        for (int right = 0; right < n; right++) {
            windowOr = OR_func(left, right, prefix_bits);
            while (windowOr >= k && left <= right) {
                mini = min(mini, right - left + 1);
                windowOr = OR_func(left + 1, right, prefix_bits);
                ++left;
            }
        }
        return mini == 1e9 ? -1 : mini;
    }
};