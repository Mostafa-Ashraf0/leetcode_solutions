class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> table;
        vector<pair<int,int>> result;
        vector<int> finalKeys;

        // store element as a key and it's frequent number as value
        for(int x: nums){
            table[x]++;
        }

        // iterate on the hashmap and store the (key, value) as pairs in vector(result)
        for(auto i = table.begin(); i != table.end(); i++){
            result.push_back({i->first, i->second});
        }

        // ascendingly sorting
        sort(result.begin(), result.end(), [](auto &a, auto &b){
            return a.second < b.second;
        });

        //get the top K frequent
        int maxE = result.size()-1;
        while(k>0){
            finalKeys.push_back(result[maxE].first);
            maxE--;
            k--;
        }

        return finalKeys;
    }
};