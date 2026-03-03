class Solution {
public:
    string invert(string s){
        for(int i = 0; i < (int)s.size(); i++){
            if(s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }
        return s;
    }

    string build(int n){
        if(n == 1) return "0";

        string prev = build(n - 1);
        string inv = invert(prev);
        reverse(inv.begin(), inv.end());
        return prev + "1" + inv;
    }

    char findKthBit(int n, int k) {
        string s = build(n);
        return s[k - 1];
    }
};