class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitalCount = 0;
        
        for(char c : word) {
            if(isupper(c)) capitalCount++;
        }
        
        if(capitalCount == word.size()) return true;          // ALL CAPS
        if(capitalCount == 0) return true;                    // all small
        if(capitalCount == 1 && isupper(word[0])) return true; // Only first capital
        
        return false;
    }
};
