class Solution {
public:
bool checkInclusion(string s1, string s2) {
	if (s1.length() > s2.length()) {
		return false;
	}
	int matchs = 0;
	vector<int> s1StrTable(26, 0);
	vector<int> s2StrTable(26, 0);

	// Count charactors
	for (int i = 0; i < s1.length(); i++) {
		s1StrTable[s1[i] - 'a']++;
		s2StrTable[s2[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		if (s1StrTable[i] == s2StrTable[i]) {
			matchs++;
		}
	}

	

	int l = 0;
	int idx = 0;
	for (int r = s1.length(); r < s2.length(); r++) {
        if (matchs == 26) return true;
		idx = s2[r] - 'a';
		s2StrTable[idx]++;

		if (s1StrTable[idx] == s2StrTable[idx]) {
			matchs++;
		}
		else if (s1StrTable[idx] + 1 == s2StrTable[idx]) {
			matchs--;
		}

		idx = s2[l] - 'a';
		s2StrTable[idx]--;

		if (s1StrTable[idx] == s2StrTable[idx]) {
			matchs++;
		}
		else if (s1StrTable[idx] - 1 == s2StrTable[idx]) {
			matchs--;
		}
		l++;

	}
	if (matchs == 26) return true;

	return false;
}
};
