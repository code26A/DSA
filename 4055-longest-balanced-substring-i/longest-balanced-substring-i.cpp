class Solution {
public:
    int longestBalanced(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            vector<int> freq(26,0);
            for(int j=i;j<s.size();j++){
                freq[s[j]-'a']++;
                int fs=-1;
                bool flag=true;
                for(int k=0;k<26;k++){
                    if(freq[k]!=0 && fs==-1) fs=freq[k];
                    else if(fs!=-1 && freq[k]!=fs && freq[k]!=0){
                        flag=false;
                        break;
                    }
                }
                if(flag) ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};