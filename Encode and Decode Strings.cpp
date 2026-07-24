// wrong solution but good thinking

class Solution {
public:

    unordered_map<int, pair<int,int>> table;

    string encode(vector<string>& strs) {
        int currentIndex = 0;
        string decoded;
        
        for(int i = 0; i < strs.size(); i++){
            string current = strs[i];
            if(strs[i] == ""){
                decoded += "+";
                table[currentIndex] = {i,0};
                currentIndex ++;
            }
            for(int j = 0; j < current.length(); j++){
                decoded += current[j];
                table[currentIndex] = {i,j};
                currentIndex ++;
            }
        }

        return decoded;
    }

    vector<string> decode(string s) {
        vector<string> final;
        string item;
        int itemIndex = 0;


        for(int i = 0; i < s.length(); i++){
            if(table[i].first != itemIndex){
                final.push_back(item);
                item = "";
                itemIndex++;
            }

            if(s[i] == '+'){
                final.push_back("");
                itemIndex++;
                continue;
            }
            
            if(i == s.length()-1){
                item += s[i];
                final.push_back(item);
                break;
            }
            item += s[i];
        }
        return final;
    }
};
