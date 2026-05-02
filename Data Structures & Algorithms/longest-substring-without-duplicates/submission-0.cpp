class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int res = 0;
        unordered_set<int> box;
        int ss_len = 0;
        for(int r = 0; r < s.length(); r++){
            while(box.find(s[r]) != box.end()){
                box.erase(s[l]);
                l++;
            }
            box.insert(s[r]);
            ss_len = max(ss_len,r - l + 1);
        }
        return ss_len;
    }
};
