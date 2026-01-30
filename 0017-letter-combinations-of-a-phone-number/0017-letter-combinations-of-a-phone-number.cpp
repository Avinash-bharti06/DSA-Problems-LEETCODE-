class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;

        // If input is empty
        if (digits.length() == 0)
            return result;

        // Digit to letter mapping (array, not hashmap)
        string mp[10] = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        // Initial empty string
        result.push_back("");

        // Iterate over digits
        for (char d : digits) {
            vector<string> temp;
            string letters = mp[d - '0'];

            for (string s : result) {
                for (char c : letters) {
                    temp.push_back(s + c);
                }
            }
            result = temp;
        }

        return result;
    }
};
