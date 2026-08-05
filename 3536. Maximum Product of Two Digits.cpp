class Solution {
public:
    int maxProduct(int n) {
        string sn = to_string(n);
        int arrItem;
        long long divisor = 1;

        vector<int> arr;
        for(int i = 0; i < sn.length(); i++){
            //get each int and store it in vector [units, 10s , 100s, 1000s, ....]
            int arrItem = (n / divisor) % 10;
            divisor *= 10;
            arr.push_back(arrItem);
        }
        //vector sorting
        sort(arr.begin(), arr.end());

        //the max product is the latest two numbers in the vector
        return arr[arr.size()-1] * arr[arr.size()-2]; 
    }
};