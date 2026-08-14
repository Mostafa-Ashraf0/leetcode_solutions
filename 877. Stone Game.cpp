class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        bool aliceTurn = true;
        int alice = 0;
        int bob = 0;
        int p1 = 0;
        int p2 = piles.size()-1;

        while(p1 < p2){
            if(aliceTurn){
                if(piles[p1] > piles[p2]){
                    alice += piles[p1];
                    p1++;
                }else{
                    alice += piles[p2];
                    p2--;
                }
            }else{
                if(piles[p1] > piles[p2]){
                    bob += piles[p2];
                    p2--;
                }else{
                    bob += piles[p1];
                    p1++;
                }
            }
            aliceTurn = !aliceTurn;
        }
        return alice > bob;
    }
};