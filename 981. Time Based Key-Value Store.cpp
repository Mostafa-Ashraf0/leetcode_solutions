class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> timeMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int low = 0;
        int high = timeMap[key].size()-1;
        int mid;

        while(low <= high){
            mid = low + (high - low) / 2;
            if(timeMap[key][mid].first == timestamp){
                return timeMap[key][mid].second;
            }else if(timeMap[key][mid].first < timestamp){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        if(high < 0){
            return "";
        }else{
            return timeMap[key][high].second;
        }

    }
};