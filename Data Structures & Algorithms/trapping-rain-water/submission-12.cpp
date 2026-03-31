class Solution {
public:
	int trap(vector<int>& height) {
		int h = 0;
		int w = 0;
		int l = 0;
		int r = 0;
		int len = 0;
		int tmp_vol = 0;
		int vol = 0;
		bool IsTrap = false;
		for (int i = 0; i < height.size(); i++) {
			if (i == 0 && height.at(i) == 0) continue;

			l = height.at(i);
			tmp_vol = 0;
			IsTrap = false;
			len = 0;
			for (int j = i + 1; j < height.size(); j++) {
				r = height.at(j);
				if (r < l) {
					tmp_vol += (l - r);
					len = j - i;
				}
				else {
					i = j-1;
					vol += tmp_vol;
					IsTrap = true;
					break;
				}
			}
			if (!IsTrap) {
				int h_max = height.at(i)-1;
				int l1 = l + 1;
				int tmp_vol2 = 0;
				int h_end = height.at(height.size() - 1);
				while (h_max > 0) {
					for (int k = i; k < height.size(); k++) {
						if (h_max > h_end) {
							bool Can_trap = false;
							for (int m = k + 1; m < height.size() - 1; m++) {
								if (height.at(m) >= h_max) {
									Can_trap = true;
									break;
								}
							}
							if (!Can_trap) {
								break;
							}
						}			
						if ( (height.at(k) < h_max) ) {
							tmp_vol2++;
						}
					}
					h_max--;
				}
				vol += tmp_vol2;
				break;
			}
		}
		return vol;
	}
};
