class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> result(size);
        vector<int> st;
        int days;
        
        for(int i = 0; i < temperatures.size(); i++){
            if(st.empty()){
                st.push_back(i);
                continue;
            }
            //compare the temp with all temps in the stack -> calculateDays -> remove temp
            while(!st.empty() && temperatures[i] > temperatures[st.back()]){
                days = i - st.back();
                result[st.back()] = days;
                st.pop_back();
            }
            st.push_back(i);

            if(i == temperatures.size()-1){
                while(!st.empty()){
                    result[st.back()] = 0;
                    st.pop_back();
                }
            }
        }
        return result;
    }
};
