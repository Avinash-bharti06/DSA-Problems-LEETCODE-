class Solution {
public:
    vector<string> ans;

    void str(int n, string s) {
        if (s.size() == n) {
            ans.push_back(s);
            return;
        }

        vector<char> temp = {'a', 'b', 'c'};

        for (int j = 0; j < 3; j++) {
            if (s.empty() || s.back() != temp[j]) {
                str(n, s + temp[j]);
            }
        }
    }

    string getHappyString(int n, int k) {
        str(n, "");

        if (k > ans.size()) return "";
        return ans[k - 1];
    }
};