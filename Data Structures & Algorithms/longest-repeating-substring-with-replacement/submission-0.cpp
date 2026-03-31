#define WL_Len (r - l + 1)
class Solution {
public:
	int characterReplacement(string s, int k) {
		unordered_set<char> t_char(s.begin(), s.end());
		int l = 0;
		int r = 0;
		int cnt = 0;
		int res = 0;
		for (char c : t_char) {
            l = 0;
            cnt = 0;
			for (int r = 0; r < s.length(); r++) {
				if (c == s[r]) {
					cnt++;
				}
				while ((WL_Len - cnt) > k) {
					if (c == s[l]) {
						cnt--;
					}
					l++;
				}
				res = max(res, WL_Len);
			}
		}
		return res;
	}

};
