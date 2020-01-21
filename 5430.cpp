#include<iostream>
#include<string>
#include<deque>
#include<algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testcase;
	cin >> testcase;

	deque<int> dq;

	while (testcase--) {
		int n;
		string op, arr;

		cin >> op;
		cin >> n;
		cin >> arr;

		string temp;	// 두 자릿수 이상의 숫자
		for (int i = 0; i < arr.length(); i++) {
			if (arr[i] == '[') continue;
			else if (arr[i] >= '0' && arr[i] <= '9')
				temp += arr[i];
			else if (arr[i] == ',' || arr[i] == ']') {
				if (!temp.empty()) {
					dq.push_back(stoi(temp));
					temp.clear();
				}
			}
		}

		bool print = true;	// 오류 여부
		bool left = true;	// print 순서

		for (int i = 0; i < op.length(); i++) {
			if (op[i] == 'R')
				left = !left;
			else if (op[i] == 'D') {
				if (dq.empty()) {
					print = false;
					break;
				}
				else {
					if (left)
						dq.pop_front();
					else
						dq.pop_back();
				}
			}
		}

		if (print) {
			cout << "[";
			int len = dq.size();

			if (left) {
				while (!dq.empty()) {
					cout << dq.front();
					dq.pop_front();
					if (!dq.empty())
						cout << ",";
				}
				cout << "]" << endl;
			}

			else {
				while (!dq.empty()) {
					cout << dq.back();
					dq.pop_back();
					if (!dq.empty())
						cout << ",";
				}
				cout << "]" << endl;
			}
		}
		else cout << "error" << endl;

		while (!dq.empty())
			dq.pop_back();
	}

	return 0;
}
