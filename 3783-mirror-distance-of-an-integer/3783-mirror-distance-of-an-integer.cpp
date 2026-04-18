class Solution {
public:
    int rev(int x){
        if(x<10) return x;
        string s = to_string(x);
        reverse(s.begin(),s.end());
        return stoi(s);
    }
    int mirrorDistance(int n) {
        int y = rev(n);
        return abs(y-n);
    }
};