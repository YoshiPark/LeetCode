#include <iostream>
#include <cctype>
#include <string>
using namespace std;
struct Node {
	char entry;
	Node *next;
	Node() {
		next = NULL;
	}
	Node(char data, Node *add_on = NULL) {
		entry = data;
		next = add_on;
	}
};
class Stack {
public:
	Stack();
	bool empty() const;
	void push(const char item);
	void pop();
	char top() const;
	int size() const;
protected:
	Node *top_node;
	int count;
};
Stack::Stack() {
	top_node = NULL;
	count = 0;
}
bool Stack::empty() const { return count == 0; }
int Stack::size() const { return count; }
char Stack::top() const {
	if (top_node != NULL)
		return top_node->entry;
}
void Stack::push(const char item) {
	if (top_node == NULL) {
		top_node = new Node(item);
		count++;
	}
	else {
		Node *temp = new Node(item, top_node);
		top_node = temp;
		count++;
	}
}
void Stack::pop() {
	if (top_node == NULL)
		return;
	if (count == 1) {
		delete top_node;
		top_node = NULL;
		count = 0;
	}
	else {
		Node *temp = top_node;
		top_node = top_node->next;
		delete temp;
		temp = NULL;
		count--;
	}
}
class MidToLast {
public:
	string transfer(string str);
};
string MidToLast::transfer(string a) {
	Stack _stack;
	string temp;
	while (!a.empty()) {
		if (isalnum(a[0])) {
			temp += a[0];
			a.erase(0, 1);
		}
		else {
			if (a[0] == ')' || a[0] == '(') {
				if (a[0] == ')') {
					while (_stack.top() != '(') {
						temp += _stack.top();
						_stack.pop();
					}
					_stack.pop();
				}
				else {
					_stack.push(a[0]);
				}
			}
			else {
				if (a[0] == '+' || a[0] == '-') {
					while (_stack.top() != '(' && _stack.size() != 0) {
						temp += _stack.top();
						_stack.pop();
					}
					_stack.push(a[0]);
				}
				else {
					while (_stack.top() != '+' && _stack.top() != '-' &&
						_stack.top() != '(' && _stack.size() != 0) {
						temp += _stack.top();
						_stack.pop();
					}
					_stack.push(a[0]);
				}
			}
			a.erase(0, 1);
		}
	}
	while (!_stack.empty()) {
		if (_stack.top() != '(' && _stack.top() != ')')
			temp += _stack.top();
		_stack.pop();
	}
	return temp;
}
int main() {
	string temp;
	cin >> temp;
	MidToLast s;
	cout << s.transfer(temp) << endl;
	return 0;
}