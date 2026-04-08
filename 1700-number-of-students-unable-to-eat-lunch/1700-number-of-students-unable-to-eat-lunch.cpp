class Solution {
public:
    int countStudents(vector<int>& s, vector<int>& sw) {
        if (s.size() != sw.size()) return s.size();

        queue<int> q;
        int n = s.size();

        for (int i = 0; i < n; i++) q.push(s[i]);

        int i = 0;
        int cnt = 0;

        while (!q.empty() && cnt < q.size()) {
            if (q.front() == sw[i]) {
                q.pop();
                i++;
                cnt = 0;
            } 
            else {
                q.push(q.front());
                q.pop();
                cnt++;
            }
        }

        return q.size();
    }
};