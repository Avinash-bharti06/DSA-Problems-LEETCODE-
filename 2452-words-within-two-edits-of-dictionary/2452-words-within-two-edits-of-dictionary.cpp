class Solution {
public:
    bool eqal(string s, string t) {
        if (s.size() != t.size()) return false; 
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) count++;
            if (count >= 3) return false;  
        }
        return count < 3;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
    
        for (int i = 0; i < queries.size(); i++) {
            for (int j = 0; j < dictionary.size(); j++) {
                if (eqal(queries[i], dictionary[j])) {
                    ans.push_back(queries[i]);
                    break;  
                }
            }
        }

        return ans;
    }
};