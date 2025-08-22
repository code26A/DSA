class Solution {
public:
    long long isValid(int mid,vector<int> &nums){
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=nums[i]/mid;
            if(nums[i]%mid!=0) ans++;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans=-1,low=1,high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(isValid(mid,piles)<=h){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};