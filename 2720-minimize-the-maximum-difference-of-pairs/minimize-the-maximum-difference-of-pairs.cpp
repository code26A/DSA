class Solution {
public:
    bool isValid(int mid, vector<int>& nums, int p) {
        int cnt = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] <= mid) {
                cnt++;
                i++; 
            }
            if (cnt >= p) return true;
        }
        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {
        if(nums.size()==1) return 0;
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back() - nums.front(), ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(mid, nums, p)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
