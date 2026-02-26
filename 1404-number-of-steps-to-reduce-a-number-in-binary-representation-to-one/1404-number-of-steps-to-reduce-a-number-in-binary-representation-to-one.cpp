class Solution {
public:
    bool checkEven(string &s) {
        return s.back() == '0';
    }

    void addOne(string &s) {
        int i = s.size() - 1;

        while (i >= 0 && s[i] == '1') {
            s[i] = '0';
            i--;
        }

        if (i >= 0) {
            s[i] = '1';
        } else {
            s = '1' + s;
        }
    }

    int numSteps(string s) {
        int steps = 0;

        while (s != "1") {
            if (checkEven(s)) {
                s.pop_back();  // divide by 2
            } else {
                addOne(s);     // add 1
            }
            steps++;
        }

        return steps;
    }
};