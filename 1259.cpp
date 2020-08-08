#include<iostream>
#include<string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		string num;
		cin >> num;

		bool check = true;
		if (num.length() == 1 && num[0] == '0') break;

		for (int i = 0; i < num.length() - 1; i++) {
			if (num[i] != num[num.length() - 1 - i]) {
				check = false;
				break;
			}
		}

		if (check) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}
