string processing_string(string ss) {
    string str_out;
    for (char c : ss) {
        if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
            if (c >= 65 && c <= 90) {
                str_out = str_out + (char)(c + 32);
            }
            else {
                str_out = str_out + (char)(c);
            }
        }
    }
    return str_out;
}
class Solution {
public:
    bool isPalindrome(string s) {
        string out = processing_string(s);
        string out_reverse = out;
        reverse(out_reverse.begin(), out_reverse.end());
        if (!out.compare(out_reverse)) {
            return true;
        }
        return false;
    }
};
