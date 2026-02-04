class Solution {
public:
    vector<int> vectork(int k) {
        vector<int> v1;
        if (k == 0) return {0};

        while (k > 0) {
            v1.push_back(k % 10);
            k /= 10;
        }
        reverse(v1.begin(), v1.end());
        return v1;
    }

    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> K = vectork(k);
        vector<int> sumed;

        int i = num.size() - 1;
        int j = K.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += num[i--];
            if (j >= 0) sum += K[j--];

            sumed.push_back(sum % 10);
            carry = sum / 10;
        }

        reverse(sumed.begin(), sumed.end());
        return sumed;
    }
};
