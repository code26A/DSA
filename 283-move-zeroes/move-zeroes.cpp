class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==1) return;
         int fz=-1;
         for(int i=0;i<nums.size();i++){
            if(nums[i]==0 && fz==-1) fz=i;
            if(nums[i]!=0 && fz!=-1){
                swap(nums[i],nums[fz]);
                fz++;
            }
         }
    }
};