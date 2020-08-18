#include<iostream>
#include<string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num = 665;
	int n;
	cin >> n;

	int cnt = 0;
	while (num++) {
		string s = to_string(num);

		if (s.find("666") != -1) cnt++;

		if (cnt == n) {
			cout << num;
			break;
		}
	}

	return 0;
}
