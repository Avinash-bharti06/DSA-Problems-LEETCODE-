class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        // Step 1: Check if valid
        if (str1 + str2 != str2 + str1)
            return "";
        
        // Step 2: Find gcd of lengths
        int len1 = str1.length();
        int len2 = str2.length();
        int g = __gcd(len1, len2);
        
        // Step 3: Return substring
        return str1.substr(0, g);
    }
};
