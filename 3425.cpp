#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<cstring>
#include <math.h>
using namespace std;

const int MAX = 1e9;
const int SIZE = 100000;

string command[SIZE];
long long pushNum[SIZE];
stack<long long> s;
int commandCnt;

void inputCommand() {
	commandCnt = 0;
	for (int i = 0; i < SIZE; i++) {
		cin >> command[i];

		commandCnt++;
		if (command[i] == "NUM")
			cin >> pushNum[i];
		else if (command[i] == "END")
			break;
		else if (command[i] == "QUIT") exit(0);
	}
}

void func() {
	for (int i = 0; i < commandCnt; i++) {
		if (command[i] == "NUM") {
			s.push(pushNum[i]);
		}
		else if (command[i] == "POP") {
			if (s.empty()) {
				cout << "ERROR\n";
				return;
			}

			s.pop();
		}
		else if (command[i] == "INV") {
			if (s.empty()) {
				cout << "ERROR\n";
				return;
			}

			long long num = s.top() * -1;

			s.pop();
			s.push(num);
		}
		else if (command[i] == "DUP") {
			if (s.empty()) {
				cout << "ERROR\n";
				return;
			}

			s.push(s.top());
		}
		else if (command[i] == "SWP") {
			if (s.size() < 2) {
				cout << "ERROR\n";
				return;
			}

			long long num1 = s.top();
			s.pop();
			long long num2 = s.top();
			s.pop();

			s.push(num1);
			s.push(num2);
		}
		else if (command[i] == "ADD") {
			if (s.size() < 2) {
				cout << "ERROR\n";
				return;
			}

			long long num1 = s.top();
			s.pop();
			long long num2 = s.top();
			s.pop();

			num1 += num2;

			if (abs(num1) > MAX) {
				cout << "ERROR\n";
				return;
			}

			s.push(num1);
		}
		else if (command[i] == "SUB") {
			if (s.size() < 2) {
				cout << "ERROR\n";
				return;
			}

			long long num1 = s.top();
			s.pop();
			long long num2 = s.top();
			s.pop();

			num2 -= num1;

			if (abs(num2) > MAX) {
				cout << "ERROR\n";
				return;
			}

			s.push(num2);
		}
		else if (command[i] == "MUL") {
			if (s.size() < 2) {
				cout << "ERROR\n";
				return;
			}

			long long num1 = s.top();
			s.pop();
			long long num2 = s.top();
			s.pop();

			if (abs(num1) > 1e8 && abs(num2) > 1e8) {
				cout << "ERROR\n";
				return;
			}

			num1 *= num2;

			if (num1 > MAX) {
				cout << "ERROR\n";
				return;
			}

			s.push(num1);
		}
		else if (command[i] == "DIV") {
			if (s.size() < 2) {
				cout << "ERROR\n";
				return;
			}

			long long num1 = s.top();
			s.pop();
			long long num2 = s.top();
			s.pop();

			if (num1 == 0) {
				cout << "ERROR\n";
				return;
			}

			num2 /= num1;

			s.push(num2);
		}
		else if (command[i] == "MOD") {
			if (s.size() < 2) {
				cout << "ERROR\n";
				return;
			}

			long long num1 = s.top();
			s.pop();
			long long num2 = s.top();
			s.pop();

			if (num1 == 0) {
				cout << "ERROR\n";
				return;
			}

			num2 %= num1;

			s.push(num2);
		}
		else if (command[i] == "END") {
			if (s.size() == 1)
				cout << s.top() << "\n";
			else {
				cout << "ERROR\n";
				return;
			}
			

		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		inputCommand();

		int t;
		cin >> t;

		while (t--) {
			int n;
			cin >> n;

			s.push(n);
			func();

			while (!s.empty()) s.pop();
		}
		cout << "\n";
	}

	return 0;
}
