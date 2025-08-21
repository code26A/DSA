class Solution {
public:
    int lower_bound(vector<int> nums,int target){
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)>>1;
            if(nums[mid]>=target){
                high=mid-1;
            }else low=mid+1;
        }
        return low;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=lower_bound(nums,target);
        int right=lower_bound(nums,target+1);
        if(left==nums.size() || nums[left]!=target) return {-1,-1};
        return {left,right-1};
    }
};