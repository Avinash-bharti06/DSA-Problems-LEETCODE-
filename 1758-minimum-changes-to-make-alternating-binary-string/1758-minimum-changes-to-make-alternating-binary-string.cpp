class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int e_cnt = 0;
        int o_cnt = 0;

        for(int i = 0; i < n; i++){
            
            //  010101
            if(i % 2 == 0){
                if(s[i] != '0') e_cnt++;
            } 
            else{
                if(s[i] != '1') e_cnt++;
            }

            //  101010
            if(i % 2 == 0){
                if(s[i] != '1') o_cnt++;
            } 
            else{
                if(s[i] != '0') o_cnt++;
            }
        }

        return min(e_cnt, o_cnt);
    }
};