#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(void) {
	string input;
	cin >> input;

	stack<char> s;

	int subtotal = 1;
	int result = 0;
	bool check = true;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(') {
			s.push(input[i]);
			subtotal *= 2;
		}
		else if (input[i] == '[') {
			s.push(input[i]);
			subtotal *= 3;
		}
		else if (input[i] == ')') {
			if (s.empty() || s.top() != '(') {
				check = false;
				break;
			}
			else {
				if (input[i - 1] == '(')
					result += subtotal;

				s.pop();
				subtotal /= 2;
			}
		}
		else if (input[i] == ']') {
			if (s.empty() || s.top() != '[') {
				check = false;
				break;
			}
			else {
				if (input[i - 1] == '[')
					result += subtotal;

				s.pop();
				subtotal /= 3;
			}
		}
	}

	if (check && s.empty())
		cout << result << endl;
	else
		cout << "0" << endl;

	return 0;
}
