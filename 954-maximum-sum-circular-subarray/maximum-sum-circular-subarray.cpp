class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum=nums[0],currSum=0,minSum=nums[0],currMin=0,total=0;
        for(int i=0;i<nums.size();i++){
            currSum=max(nums[i],currSum+nums[i]);
            maxSum=max(maxSum,currSum);
            currMin=min(nums[i],currMin+nums[i]);
            minSum=min(minSum,currMin);
            total+=nums[i];
        }
        return maxSum > 0? max(maxSum,total-minSum) : maxSum;
    }
};