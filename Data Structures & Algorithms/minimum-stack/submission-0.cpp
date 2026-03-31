class MinStack {
public:
private:
	stack<int> mStack;
	stack<int> mMin_Stack;
public:
	MinStack() {

	}

	void push(int val) {
		mStack.push(val);
		val = min(val, mMin_Stack.empty() ? val : mMin_Stack.top());
		mMin_Stack.push(val);
	}

	void pop() {
		mStack.pop();
		mMin_Stack.pop();
	}

	int top() {
		return mStack.top();
	}

	int getMin() {
		return mMin_Stack.top();
	}
};
