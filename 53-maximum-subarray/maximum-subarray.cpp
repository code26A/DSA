class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev=0;
        int maxi=-1e9;
        for(int i=0;i<nums.size();i++){
            int current=max({prev+nums[i],nums[i]});
            prev=current;
            maxi=max(maxi,current);
        }
        return maxi;
    }
};