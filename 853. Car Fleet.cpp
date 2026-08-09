class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        vector<float> st;
        float time;
        for(int i = 0; i < position.size(); i++){
            cars.push_back({position[i], speed[i]});
        }
        //sort works on first element in pair by default;
        sort(cars.begin(), cars.end());
        for(int i = cars.size()-1; i >= 0; i--){
            time = (float)(target - cars[i].first) / cars[i].second;
            if(st.empty()){
                st.push_back(time);
            }else{  
                if(time <= st.back()){
                    time = st.back();
                    st.pop_back();
                    st.push_back(time);
                }else{
                    st.push_back(time);
                }
            }

        }
        return st.size();
    }
};