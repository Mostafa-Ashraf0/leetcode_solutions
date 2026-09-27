class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, set<int>>chars;
        int result = 0;
        for(int i = 0; i < word.length(); i++){
            chars[word[i]].insert(i);
        }
        for (const auto& [key, value] : chars){
            if(islower(key) && chars.find(toupper(key)) != chars.end()){
                //* sign used to get the value (rbegin , begin returns iterator not value)
                if(*chars[key].rbegin() < *chars[toupper(key)].begin()){
                    result++;
                }
            }
        } 
        return result;
    }
};