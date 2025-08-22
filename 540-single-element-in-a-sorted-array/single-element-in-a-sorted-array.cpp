class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            int left=-1,right=-1;
            if(mid-1>=0) left=mid-1;
            if(mid+1<nums.size()) right=mid+1;
            if(left==-1 && nums[right]!=nums[mid]) return nums[mid];
            if(right==-1 && nums[left]!=nums[mid]) return nums[mid];
            if(nums[left]!=nums[mid] && nums[right]!=nums[mid]) return nums[mid];
            //observation length is odd
            //example
            // 1,1,2,3,3,4,4,5,5
            //mid=3(4 ind) 
            if(nums[mid]==nums[left]){
                if((mid-low-1)%2!=0) high=mid-2;
                else if((high-mid)%2!=0) low=mid+1;
            }else if(nums[mid]==nums[right]){
                if((mid-low)%2!=0) high=mid-1;
                else if((high-mid-1)%2!=0) low=mid+2;
            }
        }
        return -1;
    }
};