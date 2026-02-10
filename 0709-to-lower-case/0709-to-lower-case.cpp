class Solution {
public:
    char fun(char t){
        if(t >= 'A' && t <= 'Z')
            return t + ('a' - 'A');
            return t;
    }
    string toLowerCase(string s) {
        int n= s.size();
       for(int i=0;i<n;i++){
         s[i]=fun(s[i]);
       }
       return s;
    }
};