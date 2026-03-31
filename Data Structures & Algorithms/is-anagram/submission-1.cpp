class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int ascii_arr[26] = {0};
    
        for(char c:s){
            ascii_arr[c - 'a']++;
        }
        for(char c:t){
            ascii_arr[c - 'a']--;
        }

        for(int i: ascii_arr){
            if(ascii_arr[i] !=0) return false;
        }
        return true;
    }
};
