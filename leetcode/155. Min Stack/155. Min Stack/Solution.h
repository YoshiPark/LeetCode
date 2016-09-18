#include <stack>
using namespace std;
class MinStack {
public:
	void push(int x) {
		temp.push(x);
		if (min_.empty() || x <= min_.top()) min_.push(x);
	}

	void pop() {
		int num = temp.top();
		temp.pop();
		if (num == min_.top()) min_.pop();
	}

	int top() {
		return temp.top();
	}

	int getMin() {
		return min_.top();
	}
private:
	stack<int> temp;
	stack<int> min_;
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack obj = new MinStack();
* obj.push(x);
* obj.pop();
* int param_3 = obj.top();
* int param_4 = obj.getMin();
*/
