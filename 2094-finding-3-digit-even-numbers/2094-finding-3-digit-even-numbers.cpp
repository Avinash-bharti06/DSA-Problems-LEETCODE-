class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& arr) {
        
    int n = arr.size();
    vector<int> ans;
    unordered_map<int, int> m;

    // Count frequency
    for (int ele : arr) {
        m[ele]++;
    }

    // Iterate over all 3-digit even numbers
    for (int i = 100; i <= 999; i += 2) {
    int x = i;

    int a = x % 10;   // ones place digit
    x /= 10;

    int b = x % 10;   // tens place digit
    x /= 10;

    int c = x;        // hundreds place digit

    if (m.find(a) != m.end()) {
        m[a]--;
        if (m[a] == 0) m.erase(a);

        if (m.find(b) != m.end()) {
            m[b]--;
            if (m[b] == 0) m.erase(b);

            if (m.find(c) != m.end()) {
                ans.push_back(i);
            }

            m[b]++;  // restore
        }

        m[a]++;  // restore
    }
}

return ans;
        }
    };