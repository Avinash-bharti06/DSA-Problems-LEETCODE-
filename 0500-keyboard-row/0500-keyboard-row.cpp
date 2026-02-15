class Solution {
public:
    int row_map(char ch){
        ch = tolower(ch);

        if (ch=='q'||ch=='w'||ch=='e'||ch=='r'||ch=='t'||
            ch=='y'||ch=='u'||ch=='i'||ch=='o'||ch=='p')
            return 1;

        if (ch=='a'||ch=='s'||ch=='d'||ch=='f'||
            ch=='g'||ch=='h'||ch=='j'||ch=='k'||ch=='l')
            return 2;

        if (ch=='z'||ch=='x'||ch=='c'||ch=='v'||
            ch=='b'||ch=='n'||ch=='m')
            return 3;

        return 0;
    }

    vector<string> findWords(vector<string>& words) {

        int n = words.size();
        vector<vector<int>> a(n);   // create n rows

        // fill matrix
        for(int i = 0; i < n; i++){
            for(int j = 0; j < words[i].size(); j++){
                a[i].push_back(row_map(words[i][j]));
            }
        }

        vector<string> ans;

        // check each row
        for(int i = 0; i < n; i++){
            sort(a[i].begin(), a[i].end());

            if(!a[i].empty() && a[i][0] == a[i].back()){
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};
