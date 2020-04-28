#include<iostream>
#include<string>
#include<stack>

using namespace std;

const int MAX = 'Z' - 'A' + 1;

double alpha[MAX];
int n;
string s;

void input() {
	cin >> n;
	cin >> s;

	for (int i = 0; i < n; i++)
		cin >> alpha[i];
}

double func() {
	stack<double> list;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			list.push(alpha[int(s[i] - 'A')]);
		else {
			if (s[i] == '+') {
				double num1 = list.top();
				list.pop();
				double num2 = list.top();
				list.pop();

				double result = num2 + num1;

				list.push(result);
			}
			else if (s[i] == '-') {
				double num1 = list.top();
				list.pop();
				double num2 = list.top();
				list.pop();

				double result = num2 - num1;

				list.push(result);
			}
			else if (s[i] == '*') {
				double num1 = list.top();
				list.pop();
				double num2 = list.top();
				list.pop();

				double result = num2 * num1;

				list.push(result);
			}
			else if (s[i] == '/') {
				double num1 = list.top();
				list.pop();
				double num2 = list.top();
				list.pop();

				double result = num2 / num1;

				list.push(result);
			}
		}
	}

	return list.top();
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	double result = func();

	printf("%.2lf", result);

	return 0;
}
