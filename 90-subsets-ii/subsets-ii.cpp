class Solution {
public:
    void solve(int i, vector<int> temp, vector<int> &arr, set<vector<int>> &ans) {
        if(i>=arr.size()){
            ans.insert(temp);
            return;
        }
        solve(i+1,temp,arr,ans);
        temp.push_back(arr[i]);
        solve(i+1,temp,arr,ans);
        temp.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        set<vector<int>> ans;
        vector<int> temp;
        solve(0,temp, arr, ans);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};