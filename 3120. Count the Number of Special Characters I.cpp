class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> charCountU;
        unordered_map<char, int> charCountL;
        for(int i = 0; i < word.length(); i++){
            if(isupper(word[i])){
                charCountU[word[i]]++;
            }else{
                charCountL[word[i]]++;
            }
            
        }
        int result = 0;
        for (const auto& [key, value] : charCountU) {
            if(charCountL.find(tolower(key)) != charCountL.end()){
                result++;
            }
        }
        return result;
    }
};