class Solution {
public:
    bool check(char curr, char prev){
        if(prev == '0' && curr == '1') return true;
        return false;
    }

    bool checkOnesSegment(string s) {
        for(int i = 1; i < s.size(); i++){
            if(check(s[i], s[i-1])) return false;
        }
        return true;
    }
};