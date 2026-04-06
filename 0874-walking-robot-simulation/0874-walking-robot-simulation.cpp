class Solution {
public:
    char direction(char currdirn, int num) {
        if (currdirn == 'N' && num == -1) return 'E';
        if (currdirn == 'N' && num == -2) return 'W';
        if (currdirn == 'S' && num == -1) return 'W';
        if (currdirn == 'S' && num == -2) return 'E';
        if (currdirn == 'W' && num == -1) return 'N';
        if (currdirn == 'W' && num == -2) return 'S';
        if (currdirn == 'E' && num == -1) return 'S';
        if (currdirn == 'E' && num == -2) return 'N';
        return currdirn;
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> st;
        for (auto &obs : obstacles) {
            st.insert({obs[0], obs[1]});
        }

        int x = 0, y = 0;
        char dirn = 'N';
        int ans = 0;

        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == -1 || commands[i] == -2) {
                dirn = direction(dirn, commands[i]);
            } 
            else {
                int steps = commands[i];

                while (steps--) {
                    int nx = x, ny = y;

                    if (dirn == 'N') ny++;
                    else if (dirn == 'S') ny--;
                    else if (dirn == 'E') nx++;
                    else if (dirn == 'W') nx--;

                    if (st.find({nx, ny}) != st.end()) break;

                    x = nx;
                    y = ny;

                    ans = max(ans, x * x + y * y);
                }
            }
        }

        return ans;
    }
};