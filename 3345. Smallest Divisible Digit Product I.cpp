class Solution {
public:
    int smallestNumber(int n, int t) {
        int num = n;
        int n1,n2;
        while(true){
            if(num < 10){
                if(num % t == 0){
                    return num;
                }else{
                    num ++;
                }
            }else{
                n1 = num % 10;
                n2 = (num / 10) % 10;
                if((n1 * n2) % t == 0){
                    return num;
                }else{
                    num++;
                }
            }
        }
    }
};