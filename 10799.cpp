#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
	stack<char> s;
	string str;
	cin >> str;

	int sum = 0;

	for (int i = 0; str[i] != NULL; i++) {
		if (str[i] == '(')
			s.push(str[i]);
		else {	// ')' 일때
			if (str[i - 1] == ')') {
				sum++;
				s.pop();
			}
			else {
				s.pop();
				sum += s.size();
			}
		}
	}

	cout << sum << endl;

	return 0;
}
