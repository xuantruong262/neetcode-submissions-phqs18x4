class Solution {
public:
	int maxArea(vector<int>& heights) {
		unsigned int l = 0;
		unsigned int r = heights.size()-1;
		int res = 0;
		int max_vol = 0;
		int h = 0 ;
		int w = r;
		while (l < r) {
			h = min(heights.at(l), heights.at(r));
			
			res = h * w;
			max_vol = (res > max_vol) ? res : max_vol;

			if (heights.at(l) > heights.at(r)) {
				r--;
			}
			else {
				l++;
			}
			w--;
		}
		return max_vol;
	}
};
