class Solution {
public:
    string bins(int n) {
    if (n == 0) return "0";
    
    string s = "";
    while (n > 0) {
        s.push_back('0' + (n % 2));  // remainder ko char me convert
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}
    bool hasAlternatingBits(int n) {
        string t = bins(n);
        for(int i=1;i<t.size();i++){
            if(t[i]==t[i-1]) return false;
        }
        return true;
    }
};
