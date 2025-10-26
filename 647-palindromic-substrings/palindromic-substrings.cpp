class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        int cnt=0;
        for(int i=0;i<s.size();i++){
            dp[i][i]=1;
            cnt++;
            if(i<s.size()-1 && s[i]==s[i+1]){
            dp[i][i+1]=1;
                cnt++;
            } 
        }
        for(int len=3;len<=s.size();len++){
            int i=0;
            while(i<=s.size()-len){
                int j=i+len-1;
                if(s[i]==s[j] && dp[i+1][j-1]==1){
                    dp[i][j]=1;
                    cnt++;
                }
                i++;
            }
        }
        return cnt;
    }
};