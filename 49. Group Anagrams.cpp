// the ideal solution with hashmap of key(sorted string of the strs array) and value of anagrams array

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> finalList;
        unordered_map<string, vector<string>> finalMap;
        string currentString;
        string finalString;
        vector<char> currentStringArray;


        for(int i = 0; i < strs.size(); i++){
            currentString = strs[i];
            // push elelments to the array
            for(int j = 0; j < currentString.length(); j++){
                currentStringArray.push_back(currentString[j]);
            }
            // sort elements
            sort(currentStringArray.begin(), currentStringArray.end()); 

            // store elements in one string ordered
            string finalString(currentStringArray.begin(), currentStringArray.end());
            // pop elements from the array
            for(int j = 0; j < currentString.length(); j++){
                currentStringArray.pop_back();
            }
            finalMap[finalString].push_back(currentString);
        }

        for (auto it = finalMap.begin(); it != finalMap.end(); it++) {
            finalList.push_back(it->second);
        }

        return finalList;
    }
};





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


