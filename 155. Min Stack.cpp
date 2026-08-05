class MinStack {
public:
    vector<int>st;
    vector<int>mins;
    MinStack() {
        
    }

    void push(int val) {
        if(mins.size() == 0){
            mins.push_back(val);
        }else if(val <= mins.back()){
            mins.push_back(val);
        }
        st.push_back(val);
    }
    
    void pop() {
        if(mins.size() != 0 && st.back() == mins.back()){
            mins.pop_back();
        }
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return mins.back();
    }
};