class LRUCache {
public:
    int capacity;
    list<pair<int, int>>dll;
    unordered_map<int, list<pair<int, int>>::iterator> ele;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(ele.find(key) != ele.end()){
            auto it = ele[key];
            dll.splice(dll.begin(), dll, it);
            return it->second;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(ele.find(key) != ele.end()){
            auto it = ele[key];
            it->second = value;
            dll.splice(dll.begin(), dll, it);
        }else{
            if(dll.size() == capacity){
                auto last = prev(dll.end());
                ele.erase(last->first);
                dll.erase(last);
            }
            dll.push_front({key, value});
            ele[key] = dll.begin();
        }
    }
};
