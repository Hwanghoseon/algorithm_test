#include<iostream>
#include<string>
#include<cstring>

using namespace std;

const int MAX = 20 + 1;

bool visit[MAX];

void func() {
	int T;
	cin >> T;

	while (T--) {
		string op;
		int n;

		cin >> op;

		if (op == "add") {
			cin >> n;

			visit[n] = true;
		}
		else if (op == "remove") {
			cin >> n;

			visit[n] = false;
		}
		else if (op == "check") {
			cin >> n;

			if (visit[n]) cout << "1\n";
			else cout << "0\n";
		}
		else if (op == "toggle") {
			cin >> n;

			if (visit[n]) visit[n] = false;
			else visit[n] = true;
		}
		else if (op == "all")
			memset(visit, true, sizeof(visit));
		else if (op == "empty")
			memset(visit, false, sizeof(visit));
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	func();

	return 0;
}
