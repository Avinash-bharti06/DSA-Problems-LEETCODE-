class Solution {
public:
int specialChar(char ch){
    
    if (ch == '!' || ch == '@' || ch == '#' || ch == '$' || 
    ch == '%' || ch == '^' || ch == '&' || ch == '*' || 
    ch == '(' || ch == ')' || ch == '-' || ch == '+') return 1;
    return 0;
}

    bool strongPasswordCheckerII(string s) {
        int n= s.size();
        if(n<8) return false;
        int lc=0,uc=0,sc=0,nc=0;
        for(int i = 0; i < n; i++){
          if(i > 0 && s[i] == s[i-1]) return false; 
        }
        for(int i= 0;i<n;i++){
           if(s[i]>='A' && s[i]<='Z') uc++;
           else if(s[i]>='a' && s[i]<='z') lc++;
           else if(s[i]>='0' && s[i]<='9') nc++;
          
            else sc+=specialChar(s[i]);
        }
        if(lc!=0 && uc!=0 && sc!=0 && nc!=0) return true;
        return false;
    }
};