class Solution {
public:
    // items length store
    vector<int> itemIndex;

    string encode(vector<string>& strs) {
        string item;
        string decoded;
        for(int i = 0; i < strs.size(); i++){
            item = strs[i];
            // store the length
            itemIndex.push_back(item.length());
            for(int j = 0; j < item.length(); j++){
                decoded += item[j];
            }
        }
        return decoded;
    }

    vector<string> decode(string s) {
        vector<string> final;
        string encoded;
        int sIndex = 0;
        int eIndex;

        //iterate on itemIndex and push the length of each item from the string(s)....
        for(int i = 0; i < itemIndex.size(); i++){
            if(i == 0){
                eIndex = itemIndex[i];
            }else{
                eIndex += itemIndex[i];
            }
            if(itemIndex[i] == 0){
                final.push_back("");
                continue;
            }
            for(int j = sIndex; j < eIndex; j++){
                encoded += s[j];
            }
            final.push_back(encoded);
            encoded = "";
            sIndex = eIndex;
        }
        
        return final;
    }
};
