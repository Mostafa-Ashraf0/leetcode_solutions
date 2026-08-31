class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, pair<int, int>> table;
        int max = 0;
        int len = 0;
        int l = 0;
        int r = 0;

        if(s.length() == 1) return 1;
        if(s.length() == 0) return 0;

        for(int i = 0; i < s.length(); i++){
            r = i;
            if(table.find(s[i]) == table.end()){
                table[s[i]].first++;
                table[s[i]].second = i;
            }else{
                len = (r - l);
                if(len > max) max = len;
                len = 0;
                while (l <= table[s[i]].second) {
                    table.erase(s[l]);
                    l++;
                }
                table[s[i]].first++;
                table[s[i]].second = i;
            }
        }
        len = (r - l) + 1;
        if(len > max) max = len;
        return max;
    }
};
