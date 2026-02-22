class Solution {
public:
    int binaryGap(int n) {
        if(n==0) return 0;
        int i=0;
        int ans=0;
        int start=-1,end=0;
        while(i<=31){
            if((1<<i)&n){
                if(start==-1){
                    start=i;
                }
                end=i;
                ans=max(ans,end-start);
                start=end;
            }
            i++;
        }
        return ans;
    }
};