class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int>mp;
        for(int i : s) mp[i]++;
        for(int i : t){
            if(mp.find(i)!=mp.end()){
                mp[i]--;
                if(mp[i]==0)mp.erase(i);
            }
            else return false;
        }
        if(mp.size()>0) return false;
        return true;
    }
};