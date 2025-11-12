class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0,sum=nums[0];
        for(int i=0;i<nums.size();i++){
            curr=max(nums[i],curr+nums[i]);
            sum=max(sum,curr);
        }
        return sum;
    }
};