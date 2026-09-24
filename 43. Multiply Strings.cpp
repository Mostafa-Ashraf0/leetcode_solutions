class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> products(num1.length()+num2.length());
        string result;
        int start;
        if(num1 == "0" || num2 == "0") return "0";
        for(int i = num1.size()-1; i >= 0; i--){
            char x = num1[i];
            int n1 = (x - '0');
            for(int j = num2.size()-1; j >= 0; j--){
                char x = num2[j];
                int n2 = (x - '0');
                int pos = i + j + 1;
                products[pos] += n1*n2;
                //change the current value to a single number (if n >= 10) and carry the rest to the next index
                products[pos - 1] += products[pos] / 10;
                products[pos] %= 10;
            }
        }
        for(int i = 0; i < products.size(); i++){
            if(products[i] != 0){
                start = i;
                break;
            }
        }
        for(int i = start; i < products.size(); i++){
            result += products[i] + '0';
        }
        
        return result;
    }
};
