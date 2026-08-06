class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int>st;
        int n1, n2;
        string op;

        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] != "/" && tokens[i] != "-" &&
             tokens[i] != "+" && tokens[i] != "*"){
                st.push_back(stoi(tokens[i]));
             }else{
                op = tokens[i];
                n1 = st.back();
                st.pop_back();
                n2 = st.back();
                st.pop_back();
                if (op == "+")
                    st.push_back(n2+n1);
                else if (op == "-")
                    st.push_back(n2-n1);
                else if (op == "*")
                    st.push_back(n2*n1);
                else
                    st.push_back(n2/n1);

             }
        }
        return st[0];
    }
};
