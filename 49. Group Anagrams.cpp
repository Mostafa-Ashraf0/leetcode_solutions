// my first solution (brute force) but it refused because of (time limit issue, o(n2 * k) time complexity) 

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> finalList;
        unordered_map<string,bool> finalMap;

        for(int item = 0; item < strs.size(); item++){
            vector<string> innerList;
            if(finalMap[strs[item]] == true){
                continue;
            }else{
                innerList.push_back(strs[item]);
            }
            

            for(int i = item+1; i < strs.size(); i++){

                string mainItem = strs[item];
                if (mainItem.length() != strs[i].length()) {
                    continue;
                }

                unordered_map<char, int> table;
                for(int x: strs[i]){
                    table[x]++;
                }

                

                bool areEqual = false;
                if (mainItem == "" && strs[i] == "") areEqual = true;
                
                for(int j = 0; j<mainItem.length(); j++){
                    if(table[mainItem[j]]>0){
                        areEqual = true;
                        table[mainItem[j]]--;
                    }else{
                        areEqual = false;
                        break;
                    }
                }

                if(areEqual){
                    innerList.push_back(strs[i]);
                    finalMap[strs[i]] = true;
                }
            }

            if(innerList.size()>0){
                finalList.push_back(innerList);
            }
        }
        return finalList;
    }
};
