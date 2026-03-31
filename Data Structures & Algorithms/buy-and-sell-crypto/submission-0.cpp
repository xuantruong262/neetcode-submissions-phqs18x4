class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int l = 0;
		int r = 1;
		int mP = 0;

		while (r < prices.size()) {
			if (prices[l] < prices[r]) {
				mP = max(prices[r] - prices[l],mP);
			}
			else {
				l = r;
			}
			r++;
		}
		return mP;        
    }
};
