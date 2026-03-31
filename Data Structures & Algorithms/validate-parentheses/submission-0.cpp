class Solution {
public:
    bool isValid(string s) {
		stack<char> o_bracket;
		unordered_map<char, char> Close2Open = {
				{ ')','(' },
				{ '}','{' },
				{ ']','[' },
			};

		for (char c : s) {
			if (Close2Open.count(c)) {
				if (!o_bracket.empty() && (o_bracket.top() == Close2Open[c])) {
					o_bracket.pop();
				}
				else {
					return false;
				}
			}// Check Close bracket
			else {
				o_bracket.push(c);
			}
		}
		return o_bracket.empty();
    }
}; 
