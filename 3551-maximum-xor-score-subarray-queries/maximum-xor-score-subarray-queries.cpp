class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> ans(nums.size(),vector<int>(nums.size()));
        for(int i=0;i<nums.size();i++) ans[i][i]=nums[i];
        int len=2;
        while(len<=nums.size()){
            int i=0;
            while(i<=nums.size()-len){
                int j=i+len-1;
                ans[i][j]=ans[i][j-1]^ans[i+1][j];
                i++;
            }
            len++;
        }

        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()));
        for(int i=0;i<nums.size();i++) dp[i][i]=nums[i];
        for(int i=0;i<nums.size()-1;i++) dp[i][i+1] = max({ans[i][i+1],dp[i][i],dp[i+1][i+1]});

        len=3;
        while(len<=nums.size()){
            for(int i=0; i<=nums.size()-len; i++){
                int j = i+len-1;
                dp[i][j] = max(ans[i][j],max(dp[i][j-1],dp[i+1][j]));
            }
            len++;
        }

        vector<int> res(queries.size());
        for(int i=0;i<queries.size();i++){
            res[i]=dp[queries[i][0]][queries[i][1]];
        }
        return res;
    }
};