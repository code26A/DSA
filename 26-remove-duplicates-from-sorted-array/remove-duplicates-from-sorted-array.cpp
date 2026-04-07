class Solution {
public:
    int removeDuplicates(vector<int>& s) {
        int n = s.size();
        int i = 1, j = 1;
        while(j<n){
            if(s[j]!=s[j-1]){
                s[i]=s[j];
                i++;
            }
            j++;
        }
        return i;
    }
};