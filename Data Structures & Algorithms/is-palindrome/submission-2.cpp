class Solution {
public:
    bool isPalindrome(string s) {
        string my_str;
        for (char c : s) {
            if (isalnum(c)) {
                my_str += tolower(c);
            }
        }
        int c_l = 0;
        int c_r = my_str.length() - 1;
        while (c_r > c_l) {
            if (my_str[c_r] != my_str[c_l]) return false;
            c_r--;
            c_l++;

        }
        return true;
    }
};
