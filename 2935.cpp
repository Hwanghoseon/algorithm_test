#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MAX = 100;

//int num1, num2;
string num1;
string num2;
char op;

void input() {
	cin >> num1 >> op >> num2;
}

void resultPrint() {
	int cnt1 = num1.size();
	int cnt2 = num2.size();

	if (op == '*') {
		int len = cnt1 + cnt2 - 2;

		cout << "1";
		for (int i = 0; i < len; i++)
			cout << "0";
	}
	else if (op == '+') {
		if (cnt1 == cnt2) {
			cout << "2";

			for (int i = 0; i < cnt1 - 1; i++)
				cout << "0";
		}
		else {
			int len = max(cnt1, cnt2);

			for (int i = len; i >= 1; i--) {
				if (i == cnt1 || i == cnt2)
					cout << "1";
				else cout << "0";
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	resultPrint();

	return 0;
}
