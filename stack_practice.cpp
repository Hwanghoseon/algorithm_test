#include<iostream>
#include<string>
#define MAX 10001

using namespace std;

class Stack {
private:
	int list[MAX];
	int top = -1;
public:
	void push(int data) {
		top++;
		list[top] = data;
	}

	void pop() {
		top--;
	}

	int Top() {
		return list[top];
		cout << list[top] << endl;
	}

	int empty() {
		if (top == -1)
			return 1;
		else return 0;
	}

	int full() {
		if (top == MAX - 1)
			return 1;
		else return 1;
	}

	int size() {
		return (top + 1);
	}
};

int main() {
	int T;
	cin >> T;

	Stack stack;

	while (T--) {
		string str;
		cin >> str;

		if (str == "push") {
			if (stack.full()) {
				int data;
				cin >> data;

				stack.push(data);
			}
			else
				cout << "stack is full" << endl;
		}
		else if (str == "pop") {
			if (stack.empty())
				cout << "stack is empty" << endl;
			else
				stack.pop();
		}
		else if (str == "top") {
			if (stack.empty())
				cout << "stack is empty" << endl;
			else
				cout << stack.Top() << endl;
		}
		else if (str == "empty") {
			if (stack.empty())
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else if (str == "full") {
			if (stack.full())
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else if (str == "size") {
			int stack_size = stack.size();
			cout << stack_size << endl;
		}
	}
	
	return 0;
}
