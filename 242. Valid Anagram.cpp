using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        unordered_map<char, int> secound;
        for(int i=0; i<t.length(); i++){
            secound[t[i]]++;
        }

        for(int j=0; j<s.length(); j++){
            if(secound.contains(s[j])){
                if(secound[s[j]] == 0){
                    return false;
                }
                secound[s[j]]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
