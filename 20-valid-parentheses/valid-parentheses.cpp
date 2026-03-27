class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(-1);
            else if(s[i]=='{') st.push(-2);
            else if(s[i]=='[') st.push(-3);
            else if(s[i]==')'){
                if(st.empty() || st.top()!=-1 ) return false;
                st.pop();
            }
            else if(s[i]=='}'){
                if(st.empty() || st.top()!=-2) return false;
                st.pop();
            }
            else if(s[i]==']'){
                if(st.empty() || st.top()!=-3) return false;
                st.pop();
            }
        }
        if(st.empty()) return true;        
        return false;
    }
};