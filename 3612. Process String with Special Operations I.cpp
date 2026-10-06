class Solution {
public:
    string processStr(string s) {
        deque<char>str;
        string result;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '*'){
                if(str.empty()) continue;
                str.pop_back();
            }else if(s[i] == '%'){
                if(str.empty()) continue;
                deque<char>str2;
                for(int i = 0; i < str.size(); i++){
                    str2.push_front(str[i]);
                }
                str = str2;

            }else if(s[i] == '#'){
                if(str.empty()) continue;
                deque<char> str3;
                for(int j = 0; j < str.size(); j++){
                    str3.push_back(str[j]);
                }

                for(int j = 0; j < str3.size(); j++){
                    str.push_back(str3[j]);
                }
            }else{
                str.push_back(s[i]);
            }
        }
        for(int i = 0; i < str.size(); i++){
            result += str[i];
        }
    return result;
    }
};