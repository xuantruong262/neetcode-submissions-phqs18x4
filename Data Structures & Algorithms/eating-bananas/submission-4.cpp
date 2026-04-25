class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int k = 0;
        int m = 0;
        
        while(l <= r){
            m = l+(r-l)/2;
            int compl_h = 0;
            //Check with h
            for(int i = 0; i< piles.size();i++){
                compl_h += (piles[i] + m - 1)  / m;
            }

            if(compl_h <= h){
                r = m - 1;
                k = m;
            }
            else
            {
                l = m + 1;
            }
        }
        // Check smaller than k
        return k;
    }
};
