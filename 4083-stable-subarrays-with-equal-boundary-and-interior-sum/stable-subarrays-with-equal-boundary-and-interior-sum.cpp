class Solution {
public:
    long long countStableSubarrays(vector<int>& nums) {
       int n=nums.size();
        long long ans=0,sum=0;
        map<pair<long long,long long>,long long> m;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            long long sum_req=sum-2*nums[i];
            if(m.find({sum_req,nums[i]})!=m.end())
            ans+=m[{sum_req,nums[i]}];
            m[{sum,nums[i]}]++;
        }
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1] && nums[i]==0)
            ans--;
        }
        return ans;
    }
};