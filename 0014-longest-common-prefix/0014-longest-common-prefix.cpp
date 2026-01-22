class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1) return strs[0];
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string first = strs[0];
        string last = strs[n-1];
        string s = "";
        for(int i=0; i<first.length(); i++) {
            if(first[i] == last[i]) {
                s += first[i];
            }
            else break;  // stop when mismatch
        }
        return s;
    }
};
