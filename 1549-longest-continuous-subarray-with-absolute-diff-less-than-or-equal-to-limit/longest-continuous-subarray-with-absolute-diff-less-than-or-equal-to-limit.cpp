class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int i = 0, j = 0, ans = 0;

        while (j < nums.size()) {
            s.insert(nums[j]);

            int mini = *s.begin();
            int maxi = *s.rbegin();

            while (maxi - mini > limit) {
                s.erase(s.find(nums[i]));
                i++;
                mini = *s.begin();
                maxi = *s.rbegin();
            }

            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};
