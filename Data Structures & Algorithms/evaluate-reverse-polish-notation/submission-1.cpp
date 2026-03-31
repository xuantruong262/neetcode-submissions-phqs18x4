class Solution {
public:
    int evalRPN(vector<string>& tokens) {
		stack<int> operant;
		int a = 0;
		int b = 0;
		int res = 0;
		for (string c : tokens) {
			if (c == "+") {
				b = operant.top(); operant.pop();
				a = operant.top(); operant.pop();
				res = a + b;
				operant.push(res);
			}
			else if (c == "-") {
				b = operant.top(); operant.pop();
				a = operant.top(); operant.pop();
				res = a - b;
				operant.push(res);
			}
			else if (c == "*") {
				b = operant.top(); operant.pop();
				a = operant.top(); operant.pop();
				res = a * b;
				operant.push(res);
			}
			else if (c == "/") {
				b = operant.top(); operant.pop();
				a = operant.top(); operant.pop();
				res = a / b;
				operant.push(res);
			}
			else {
				int x = 0;
				stringstream ss(c);
				ss >> x;
				operant.push(x);
			}
		}
		return operant.top();        
    }
};
