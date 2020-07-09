#include<iostream>
#include<string>
#include<stack>

using namespace std;

int getPriority(char op) {
	if (op == '(' || op == ')') return 5;
	else if (op == '*' || op == '/') return 4;
	else if (op == '+' || op == '-') return 3;
	else return 2;
}

string changeString(string input) {
	stack<char> op;
	string result;
	for (int i = 0; i < input.length(); i++) {
		// 연산자
		if (input[i] == '(')
			op.push('(');
		else if (input[i] == ')') {
			while (!op.empty() && op.top() != '(') {
				result += op.top();
				op.pop();
			}
			// '(' pop
			op.pop();
		}
		else if (input[i] == '*' || input[i] == '/') {
			while (!op.empty() && (getPriority(op.top()) >= getPriority(input[i]))) {
				// '(' 나오면 break;
				if (op.top() == '(')
					break;
				result += op.top();
				op.pop();
			}
			op.push(input[i]);
		}
		else if (input[i] == '+' || input[i] == '-') {
			while (!op.empty() && (getPriority(op.top()) >= getPriority(input[i]))) {
				// '(' 나오면 break;
				if (op.top() == '(')
					break;
				result += op.top();
				op.pop();
			}
			op.push(input[i]);
		}
		// 피연산자
		else result += input[i];
	}

	// stack op에 연산자가 남아 있을 경우
	while (!op.empty()) {
		result += op.top();
		op.pop();
	}

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string input;
	cin >> input;

	cout << changeString(input) << "\n";

	return 0;
}
