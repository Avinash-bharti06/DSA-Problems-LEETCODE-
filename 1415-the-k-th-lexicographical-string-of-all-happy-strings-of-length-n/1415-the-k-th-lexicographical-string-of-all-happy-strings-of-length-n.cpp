class Solution {
public:
    string ans = "";
    int count = 0;

    void solve(int n, int k, string &temp) {
        if (!ans.empty()) return;

        if (temp.size() == n) {
            count++;
            if (count == k) ans = temp;
            return;
        }

        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!temp.empty() && temp.back() == ch) continue;

            temp.push_back(ch);
            solve(n, k, temp);
            temp.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        if (k > 3 * (1 << (n - 1))) return "";

        string temp = "";
        solve(n, k, temp);
        return ans;
    }
};