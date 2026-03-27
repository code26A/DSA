class Solution {
public:
    set<int> s;
    void solve(vector<int> temp, vector<int> &nums, vector<vector<int>> &ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int j=0;j<nums.size();j++){
            if(s.find(nums[j])!=s.end()) continue;
            temp.push_back(nums[j]);
            s.insert(nums[j]);
            solve(temp,nums,ans);
            temp.pop_back();
            s.erase(nums[j]);
        }
        return;
    }   
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(temp,nums,ans);
        return ans;
    }
};