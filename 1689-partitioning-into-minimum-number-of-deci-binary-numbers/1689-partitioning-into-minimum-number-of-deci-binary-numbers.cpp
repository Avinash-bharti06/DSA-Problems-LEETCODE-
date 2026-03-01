class Solution {
public:
    int minPartitions(string s) {
        char max_Num=s[0];
    for(int i = 1; i < s.length(); i++) {
        if(s[i] > max_Num) {
            max_Num = s[i];
        }
    }    int x = max_Num - '0';
         return x;
    }
};