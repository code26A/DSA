class Solution {
public:
    bool isvalid(int mid,vector<int> &nums,int k){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                cnt++;
                i++;
            }
        }
        return cnt>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int low=*min_element(nums.begin(),nums.end()),high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isvalid(mid,nums,k)){
                high=mid-1;
            }else low=mid+1;
        }
        return low;
    }
};