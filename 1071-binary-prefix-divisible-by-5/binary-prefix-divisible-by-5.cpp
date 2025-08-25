class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans(nums.size(), false);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = (sum * 2 + nums[i]) % 5;
            if (sum == 0) ans[i] = true;
        }
        return ans;
    }
};
