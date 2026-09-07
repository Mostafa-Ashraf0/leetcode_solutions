class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1Map;
        unordered_map<char, int> s2Map;
        int l = 0;
        int r;
        int win;

        for(int i = 0; i < s1.length(); i++){
            s1Map[s1[i]]++;
        }

        for(int i = 0; i < s2.length(); i++){
            r = i;
            win = r - l + 1;
            s2Map[s2[i]]++;
            while(win == s1.length()){
                if(s1Map == s2Map) return true;
                s2Map[s2[l]]--;
                if (s2Map[s2[l]] == 0) s2Map.erase(s2[l]);
                l++;
                win = r - l + 1;
            }
        }
        return false;
    }
};
