class Solution {
public:
    bool ispair(char s,char t){
        if(s=='(' && t==')')return true;
        if(s=='{' && t=='}') return true;
        if(s=='[' && t==']') return true;
        return false;
    }

    bool isValid(string s) {
        int n = s.size();
        if(n==0) return true;

        stack<char> st;

        for(int i=0;i<n;i++){
            if(!st.empty() && ispair(st.top(), s[i])){
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        return st.empty();
    }
};