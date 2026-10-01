class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int i = cost.size()-1;
        int ideal = 0;
        if(cost.size() == 1) return cost[i];
        if(cost.size() == 2) return cost[i] + cost[i-1];
        sort(cost.begin(), cost.end());
        while(i >= 2){
            for(int j = 0; j < 2; j++){
                ideal += cost[i];
                i--;
            }
            i--;
        }
        while(i >= 0){
            ideal += cost[i];
            i--;
        }
        return ideal;
    }
};