class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end(),greater<int>());
        long long ans=0;
        int len=0;
        if(n%2==0){
            len=n/2-1;
        }else{
            len=n/2;
        }
        for(int i=0;i<n;i++){
            if(i<=len){
                ans+=nums[i];
            }else ans-=nums[i];
        }
        return ans;
    }
};