class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> table;
        int finalSeq = 0;
        int seq = 1;

        for(int x: nums){
            table[x]++;
        }

        /*i tried at first to iterate on nums but it gives me time limit error because
        there are many duplicate numbers in latest test cases so it's ideal to iterate on the hashmap*/
        for(auto x: table){
            //if it's a sequence start?!
            //by identifing if the key exists(it exists so it's > 0)
            if(table.find(x.first - 1) == table.end()){
            int next = 1;
            //calculate the sequence
            while(true){
                if(table.find(x.first + next) != table.end()){
                    seq++;
                    next++;
                }else{
                    if(finalSeq < seq){
                        finalSeq = seq;
                    }
                    seq = 1;
                    next = 1;
                    break;
                }
            }
         }
        }
        return finalSeq;
    }
};
