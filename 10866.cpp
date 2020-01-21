#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	deque<int> dq;

	string op;
	while (n--) {
		int value;
		cin >> op;

		if (op == "push_back") {
			cin >> value;
			
			dq.push_back(value);
		}
		else if (op == "push_front") {
			cin >> value;

			dq.push_front(value);
		}
		else if (op == "pop_front") {
			if (dq.empty())
				cout << "-1" << endl;
			else {
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}
		else if (op == "pop_back") {
			if (dq.empty())
				cout << "-1" << endl;
			else {
				cout << dq.back() << endl;
				dq.pop_back();
			}
		}
		else if (op == "size") {
			cout << dq.size() << endl;
		}
		else if (op == "empty") {
			cout << dq.empty() << endl;
		}
		else if (op == "front") {
			if (dq.empty())
				cout << "-1" << endl;
			else cout << dq.front() << endl;
		}
		else if (op == "back") {
			if (dq.empty())
				cout << "-1" << endl;
			else cout << dq.back() << endl;
		}
	}

	return 0;
}
