class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> r, d;

        // store indices
        for(int i = 0; i < n; i++){
            if(senate[i] == 'R') r.push(i);
            else d.push(i);
        }

        // simulate rounds
        while(!r.empty() && !d.empty()){
            int r_idx = r.front(); r.pop();
            int d_idx = d.front(); d.pop();

            if(r_idx < d_idx){
                // R bans D
                r.push(r_idx + n);
            } else {
                // D bans R
                d.push(d_idx + n);
            }
        }

        return r.empty() ? "Dire" : "Radiant";
    }
};