class Solution {
public:
    bool isValid(string s) {
        vector<char> st;

        if(s.length() % 2 != 0 || s.length() == 0){
            return false;
        }

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '{' || s[i] == '[' || s[i] == '('){
                st.push_back(s[i]);
            }else{
                if(st.empty()) return false;
                if(s[i] == '}' && st.back() != '{') return false;
                if(s[i] == ')' && st.back() != '(') return false;
                if(s[i] == ']' && st.back() != '[') return false;
                st.pop_back();
            }
        }
        return st.empty();
    }
};
